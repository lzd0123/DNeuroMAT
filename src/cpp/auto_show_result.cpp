#include "auto_show_result.h"
#include <iostream>

using namespace std;

bool showReconstructionResult(V3DPluginCallback2 &callback, Image4DSimple *image, char *swcPath) {
    if (image == nullptr) {
        cerr << "[ERROR]: input image is invalid." << endl;
        return false;
    }
    if (swcPath == nullptr) {
        cerr << "[ERROR]: input .swc file is invalid." << endl;
        return false;
    }
    v3dhandle imageWindow = callback.newImageWindow("reconstruction_result");
    if (!callback.setImage(imageWindow, image)) {
        cerr << "[ERROR]: failed to set image." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    View3DControl *viewControl = callback.getView3DControl(imageWindow);
    if (viewControl == nullptr) {
        cerr << "[ERROR]: failed to get view3d control." << endl;
        return false;
    }
    viewControl->loadObjectFromFile(QString(swcPath));
    return true;
}

bool showReconstructionResult(V3DPluginCallback2 &callback, v3dhandle &imageWindow, Image4DSimple *image, char *swcPath) {
    if (imageWindow == nullptr) return showReconstructionResult(callback, image, swcPath);
    if (swcPath == nullptr) {
        cerr << "[ERROR]: input .swc file is invalid." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    View3DControl *viewControl = callback.getView3DControl(imageWindow);
    if (viewControl == nullptr) {
        cerr << "[ERROR]: failed to get view3d control." << endl;
        return false;
    }
    viewControl->loadObjectFromFile(QString(swcPath));
    return true;
}

bool showReconstructionResult(V3DPluginCallback2 &callback, char *imagePath, char *swcPath) {
    if (imagePath == nullptr) {
        cerr << "[ERROR]: input image is invalid." << endl;
        return false;
    }
    if (swcPath == nullptr) {
        cerr << "[ERROR]: input .swc file is invalid." << endl;
        return false;
    }
    v3dhandle imageWindow = callback.newImageWindow("reconstruction_result");
    Image4DSimple *image = callback.loadImage(imagePath);
    if (image == nullptr) {
        cerr << "[ERROR]: failed to load input image." << endl;
        return false;
    }
    if (!callback.setImage(imageWindow, image)) {
        cerr << "[ERROR]: failed to set image." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    View3DControl *viewControl = callback.getView3DControl(imageWindow);
    if (viewControl == nullptr) {
        cerr << "[ERROR]: failed to get view3d control." << endl;
        return false;
    }
    viewControl->loadObjectFromFile(QString(swcPath));
    return true;
}

bool showReconstructionResult(V3DPluginCallback2 &callback, v3dhandle &imageWindow, char *imagePath, char *swcPath) {
    if (imageWindow == nullptr) return showReconstructionResult(callback, imagePath, swcPath);
    if (swcPath == nullptr) {
        cerr << "[ERROR]: input .swc file is invalid." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    View3DControl *viewControl = callback.getView3DControl(imageWindow);
    if (viewControl == nullptr) {
        cerr << "[ERROR]: failed to get view3d control." << endl;
        return false;
    }
    viewControl->loadObjectFromFile(QString(swcPath));
    return true;
}

bool showSegmentationResult(V3DPluginCallback2 &callback, Image4DSimple *segImage) {
    if (segImage == nullptr) {
        cerr << "[ERROR]: input segmentation image is invalid." << endl;
        return false;
    }
    v3dhandle imageWindow = callback.newImageWindow("segmentation_result");
    if (!callback.setImage(imageWindow, segImage)) {
        cerr << "[ERROR]: failed to set segmentation image." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    return true;
}

bool showSegmentationResult(V3DPluginCallback2 &callback, v3dhandle &imageWindow, Image4DSimple *segImage) {
    if (imageWindow == nullptr) return showSegmentationResult(callback, segImage);
    if (segImage == nullptr) {
        cerr << "[ERROR]: input segmentation image is invalid." << endl;
        return false;
    }
    if (!callback.setImage(imageWindow, segImage)) {
        cerr << "[ERROR]: failed to set segmentation image." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    return true;
}

bool showSegmentationResult(V3DPluginCallback2 &callback, char *segImagePath) {
    if (segImagePath == nullptr) {
        cerr << "[ERROR]: input segmentation image path is invalid." << endl;
        return false;
    }
    v3dhandle imageWindow = callback.newImageWindow(QString(segImagePath));
    Image4DSimple *segImage = callback.loadImage(segImagePath);
    if (segImage == nullptr) {
        cerr << "[ERROR]: failed to load segmentation image." << endl;
        return false;
    }
    if (!callback.setImage(imageWindow, segImage)) {
        cerr << "[ERROR]: failed to set segmentation image." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    return true;
}

bool showSegmentationResult(V3DPluginCallback2 &callback, v3dhandle &imageWindow, char *segImagePath) {
    if (imageWindow == nullptr) return showSegmentationResult(callback, segImagePath);
    Image4DSimple *segImage = callback.loadImage(segImagePath);
    if (segImage == nullptr) {
        cerr << "[ERROR]: failed to load segmentation image." << endl;
        return false;
    }
    if (!callback.setImage(imageWindow, segImage)) {
        cerr << "[ERROR]: failed to set segmentation image." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    return true;
}

bool showCriticalPoints(V3DPluginCallback2 &callback, Image4DSimple *image, char *markerPath) {
    if (image == nullptr) {
        cerr << "[ERROR]: input image is invalid." << endl;
        return false;
    }
    if (markerPath == nullptr) {
        cerr << "[ERROR]: input .swc file is invalid." << endl;
        return false;
    }
    v3dhandle imageWindow = callback.newImageWindow("critical_points");
    if (!callback.setImage(imageWindow, image)) {
        cerr << "[ERROR]: failed to set image." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    View3DControl *viewControl = callback.getView3DControl(imageWindow);
    if (viewControl == nullptr) {
        cerr << "[ERROR]: failed to get view3d control." << endl;
        return false;
    }
    viewControl->loadObjectFromFile(QString(markerPath));
    return true;
}

bool showCriticalPoints(V3DPluginCallback2 &callback, v3dhandle &imageWindow, Image4DSimple *image, char *markerPath) {
    if (imageWindow == nullptr) return showCriticalPoints(callback, image, markerPath);
    if (markerPath == nullptr) {
        cerr << "[ERROR]: input .swc file is invalid." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    View3DControl *viewControl = callback.getView3DControl(imageWindow);
    if (viewControl == nullptr) {
        cerr << "[ERROR]: failed to get view3d control." << endl;
        return false;
    }
    viewControl->loadObjectFromFile(QString(markerPath));
    return true;
}

bool showCriticalPoints(V3DPluginCallback2 &callback, char *imagePath, char *markerPath) {
    if (imagePath == nullptr) {
        cerr << "[ERROR]: input image is invalid." << endl;
        return false;
    }
    if (markerPath == nullptr) {
        cerr << "[ERROR]: input .swc file is invalid." << endl;
        return false;
    }
    v3dhandle imageWin = callback.currentImageWindow();
    if (!imageWin) imageWin = callback.newImageWindow(imagePath);
    Image4DSimple *image = callback.loadImage(imagePath);
    if (image == nullptr) {
        cerr << "[ERROR]: failed to load input image." << endl;
        return false;
    }
    if (!callback.setImage(imageWin, image)) {
        cerr << "[ERROR]: failed to set image." << endl;
        return false;
    }
    callback.open3DWindow(imageWin);
    View3DControl *viewControl = callback.getView3DControl(imageWin);
    if (viewControl == nullptr) {
        cerr << "[ERROR]: failed to get view3d control." << endl;
        return false;
    }
    viewControl->loadObjectFromFile(QString(markerPath));
    return true;
}

bool showCriticalPoints(V3DPluginCallback2 &callback, v3dhandle &imageWindow, char *imagePath, char *markerPath) {
    if (imageWindow == nullptr) return showCriticalPoints(callback, imagePath, markerPath);
    if (markerPath == nullptr) {
        cerr << "[ERROR]: input .swc file is invalid." << endl;
        return false;
    }
    callback.open3DWindow(imageWindow);
    View3DControl *viewControl = callback.getView3DControl(imageWindow);
    if (viewControl == nullptr) {
        cerr << "[ERROR]: failed to get view3d control." << endl;
        return false;
    }
    viewControl->loadObjectFromFile(QString(markerPath));
    return true;
}