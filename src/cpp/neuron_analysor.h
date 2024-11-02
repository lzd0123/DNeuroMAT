#ifndef __NEURON_ANALYSOR_H__
#define __NEURON_ANALYSOR_H__

#include <QtCore>
#include <QtGui>
#include <v3d_interface.h>
#include "dialog.h"
#include "auto_show_result.h"
#include <memory.h>

class NeuronAnalysor
{
private:
    V3DPluginCallback2& callback;
    InterfaceDialog* parameter;
    bool autoShowResult;
    enum {Segmentation = 0, Tracing, Detection};
public:
    NeuronAnalysor(V3DPluginCallback2& cb, InterfaceDialog* dialog);
    ~NeuronAnalysor();
    QFileInfoList findImage(const QString& path);
    bool run();
};

#endif//__NEURON_ANALYSOR_H__