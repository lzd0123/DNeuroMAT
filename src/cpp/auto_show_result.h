#ifndef __AUTO_SHOW_RESULTS_H__
#define __AUTO_SHOW_RESULTS_H__

#include <v3d_interface.h>

bool showReconstructionResult(V3DPluginCallback2 &callback, Image4DSimple *image, char *swcPath);
bool showReconstructionResult(V3DPluginCallback2 &callback, v3dhandle &imageWindow, Image4DSimple *image, char *swcPath);
bool showReconstructionResult(V3DPluginCallback2 &callback, char *imagePath, char *swcPath);
bool showReconstructionResult(V3DPluginCallback2 &callback, v3dhandle &imageWindow, char *imagePath, char *swcPath);

bool showSegmentationResult(V3DPluginCallback2 &callback, Image4DSimple *segImage);
bool showSegmentationResult(V3DPluginCallback2 &callback, v3dhandle &imageWindow, Image4DSimple *segImage);
bool showSegmentationResult(V3DPluginCallback2 &callback, char *segImagePath);
bool showSegmentationResult(V3DPluginCallback2 &callback, v3dhandle &imageWindow, char *segImagePath);

bool showCriticalPoints(V3DPluginCallback2 &callback, Image4DSimple *image, char *markerPath);
bool showCriticalPoints(V3DPluginCallback2 &callback, v3dhandle &imageWindow, Image4DSimple *image, char *markerPath);
bool showCriticalPoints(V3DPluginCallback2 &callback, char *imagePath, char *markerPath);
bool showCriticalPoints(V3DPluginCallback2 &callback, v3dhandle &imageWindow, char *imagePath, char *markerPath);
#endif//__AUTO_SHOW_RESULTS_H__