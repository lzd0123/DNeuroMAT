#include "v3d_message.h"
#include <vector>
#include "neuron_analysor_plugin.h"
#include "dialog.h"
#include "neuron_analysor.h"

using namespace std;
Q_EXPORT_PLUGIN2(neuron_analysor, NeuronAnalysorPlugin);

QStringList NeuronAnalysorPlugin::menulist() const {
    return QStringList()
            << tr("Start Menu")
            << tr("About");
}

QStringList NeuronAnalysorPlugin::funclist() const {
    return QStringList()
            << tr("func1")
            << tr("func2")
            << tr("help");
}

void NeuronAnalysorPlugin::domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent) {
    if (menu_name == tr("Start Menu")) {
        InterfaceDialog dialog(callback);
        if (dialog.exec() != QDialog::Accepted) {
            return;
        }
        NeuronAnalysor analysor(callback, &dialog);
        analysor.run();
    } else {
        v3d_msg(tr(". "));
    }
}

bool NeuronAnalysorPlugin::dofunc(const QString &func_name, const V3DPluginArgList &input, V3DPluginArgList &output,
                                  V3DPluginCallback2 &callback, QWidget *parent) {
    vector<char *> infiles, inparas, outfiles;
    if (input.size() >= 1) infiles = *((vector<char *> *) input.at(0).p);
    if (input.size() >= 2) inparas = *((vector<char *> *) input.at(1).p);
    if (output.size() >= 1) outfiles = *((vector<char *> *) output.at(0).p);

    if (func_name == tr("func1")) {
        v3d_msg("To be implemented.");
    } else if (func_name == tr("func2")) {
        v3d_msg("To be implemented.");
    } else if (func_name == tr("help")) {
        v3d_msg("To be implemented.");
    } else return false;


    return true;
}

