#include "neuron_analysor.h"

NeuronAnalysor::NeuronAnalysor(V3DPluginCallback2 &cb, InterfaceDialog *dialog) :
        callback(cb), parameter(dialog), autoShowResult(true) {

}

NeuronAnalysor::~NeuronAnalysor() {

}

QFileInfoList NeuronAnalysor::findImage(const QString &path) {
    QFileInfoList imageList;
    QFileInfo imageInfo(path);
    if (imageInfo.isFile() && imageInfo.absoluteFilePath().endsWith(".tif")) {
        imageList.push_back(imageInfo);
        return imageList;
    } else if (imageInfo.isDir()) {
        imageList.append(QDir(path).entryInfoList(QStringList("*.tif"), QDir::NoDotAndDotDot | QDir::Files));
        autoShowResult = false;
    }
    return imageList;
}

bool NeuronAnalysor::run() {
    QString imagePath = parameter->getImagePath();
    QFileInfoList imageList = findImage(imagePath);
    if (imageList.isEmpty()) {
        QMessageBox::warning(parameter, "Warning", "Can't find any .tif image, please check your image path.");
        return false;
    }
    QString outputPath = parameter->getOutputPath();
    if (outputPath.isEmpty()) {
        QMessageBox::warning(parameter, "Warning", "Output path is empty.");
        return false;
    }
    if (parameter->isEnvsEmpty()) {
        QMessageBox::warning(parameter, "Warning", "Python virtual environment is empty.");
        return false;
    }
    QDir outputDir(outputPath);
    outputDir.mkpath(".");
    parameter->saveParameters(outputPath);
    int functionIndex = parameter->getFunctionIndex();
    if (functionIndex == Segmentation || (functionIndex == Tracing && parameter->isTracingWithSegmentation()) ||
        (functionIndex == Detection && parameter->isDetectionWithSegmentation())) {
        QString segMethodName = parameter->getSegMethodName();
        qDebug() << "Using " << segMethodName << " for segmentation.";
#ifdef _WIN32
        int ret = system(qPrintable(
                                 QString("conda activate %1 && python ../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/src/python/run_%2.py -i %3 -o %4")
                                         .arg(parameter->getPythonEnv(), segMethodName, imagePath, outputPath)));
#else
        int ret = system(qPrintable(
                                 QString("source activate %1 && python ../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/src/python/run_%2.py -i %3 -o %4")
                                         .arg(parameter->getPythonEnv(), segMethodName, imagePath, outputPath)));
#endif
        if (ret) return false;
    }

    if (functionIndex == Tracing) {
        QString traMethodName = parameter->getTraMethodName();
        qDebug() << "Using " << traMethodName << " for tracing.";
#ifdef _WIN32
        int ret = system(qPrintable(
                                 QString("conda activate %1 && python ../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/src/python/run_%2.py -i %3 -o %4")
                                         .arg(parameter->getPythonEnv(), traMethodName, imagePath, outputPath)));
#else
        int ret = system(qPrintable(
                                 QString("source activate %1 && python ../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/src/python/run_%2.py -i %3 -o %4")
                                         .arg(parameter->getPythonEnv(), traMethodName, imagePath, outputPath)));
#endif
        if (ret) return false;
    } else if (functionIndex == Detection) {
        QString detMethodName = parameter->getDetMethodName();
        qDebug() << "Using " << detMethodName << " for detection.";
#ifdef  _WIN32
        int ret = system(qPrintable(
                                 QString("conda activate %1 && python ../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/src/python/run_%2.py -i %3 -o %4")
                                         .arg(parameter->getPythonEnv(), detMethodName, imagePath, outputPath)));
#else
        int ret = system(qPrintable(
                                 QString("source activate %1 && python ../../vaa3d_tools/released_plugins/v3d_plugins/DNeuroMAT/src/python/run_%2.py -i %3 -o %4")
                                         .arg(parameter->getPythonEnv(), detMethodName, imagePath, outputPath)));
#endif
        if (ret) return false;
    }
    if (!autoShowResult) {
        QString result("All results have been saved to\n" + outputPath);
        QMessageBox::information(parameter, "result", result);
        return true;
    }

    QString imageBaseName = imageList.front().baseName();
    v3dhandle currentWindow = callback.currentImageWindow();
    if (functionIndex == 0) {
        return showSegmentationResult(callback, currentWindow,
                                      QString(outputPath + "/" + imageBaseName +
                                              "_seg.tif").toUtf8().data());
    } else if (functionIndex == 1) {
        return showReconstructionResult(callback, currentWindow, imagePath.toUtf8().data(),
                                        QString(outputPath + "/" + imageBaseName + ".swc").toUtf8().data());
    } else if (functionIndex == 2) {
        return showCriticalPoints(callback, currentWindow, imagePath.toUtf8().data(),
                                  QString(outputPath + "/" + imageBaseName + ".marker").toUtf8().data());
    } else {
        QString result;
        result.append("segmentation result has been saved to\n");
        result.append(outputPath + "/" + imageBaseName + "_seg.tif\n");
        result.append("tracing result has been saved to\n");
        result.append(outputPath + "/" + imageBaseName + ".swc\n");
        result.append("detection result has been saved to\n");
        result.append(outputPath + "/" + imageBaseName + ".marker\n");
        QMessageBox::information(parameter, "result", result);
        return true;
    }
}
