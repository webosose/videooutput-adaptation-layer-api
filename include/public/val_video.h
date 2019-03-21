// Copyright (c) 2017-2019 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef VAL_VIDEO_API_H
#define VAL_VIDEO_API_H

#include "val_common.h"
#include <pbnjson.hpp>
#include <string>
#include <vector>

// Define commands for set/getParam()

// Raspberry Pi specifications(DRM)
#define VAL_CTRL_DRM_RESOURCES "DRMResources"
#define VAL_CTRL_NUM_CONNECTOR "NumConnector"

typedef enum {
    VAL_VSC_INPUTSRC_AVD = 0,
    VAL_VSC_INPUTSRC_ADC,
    VAL_VSC_INPUTSRC_HDMI,
    VAL_VSC_INPUTSRC_VDEC,
    VAL_VSC_INPUTSRC_AV,
    VAL_VSC_INPUTSRC_ATV,
    VAL_VSC_INPUTSRC_JPEG,
    VAL_VSC_INPUTSRC_MAX = VAL_VSC_INPUTSRC_JPEG,
    VAL_VSC_INPUTSRC_MAXN,
} VAL_VSC_INPUT_TYPE_T;

typedef enum {
    VAL_VIDEO_WID_MIN = 0,                 /**< WID min */
    VAL_VIDEO_WID_0   = VAL_VIDEO_WID_MIN, /**< WID main window */
    VAL_VIDEO_WID_1,                       /**< WID sub window */
    VAL_VIDEO_WID_2,
    VAL_VIDEO_WID_3,
    VAL_VIDEO_WID_MAX = VAL_VIDEO_WID_3, /**< WID max */
    VAL_VIDEO_WID_MAXN,                  /**< WID max number */
} VAL_VIDEO_WID_T;

typedef enum {
    VAL_VSC_OUTPUT_DISPLAY_MODE = 0,
    VAL_VSC_OUTPUT_VENC_MODE,
    VAL_VSC_OUTPUT_MEMORY_MODE,
    VAL_VSC_OUTPUT_AVE_MODE,
    VAL_VSC_OUTPUT_MAX = VAL_VSC_OUTPUT_AVE_MODE,
    VAL_VSC_OUTPUT_MAXN,
} VAL_VSC_OUTPUT_MODE_T;

typedef struct VAL_VSC_INPUT_SRC_INFO {
    VAL_VSC_INPUT_TYPE_T type;
    UINT8 attr;
    UINT8 resourceIndex;
} VAL_VSC_INPUT_SRC_INFO_T;

typedef struct {
    UINT16 x; /**< horizontal Start Position in pixel [0,].*/
    UINT16 y; /**< vertical	Start Position in pixel [0,].*/
    UINT16 w; /**< horizontal Size(Width)    in pixel [0,].*/
    UINT16 h; /**< vertical	Size(Height)   in pixel [0,].*/
} VAL_VIDEO_RECT_T;

typedef struct {
    VAL_VIDEO_WID_T wId; // 0: bottom, 1: bottom+1,..
    UINT8 uAlpha;        // 0 ~ 255
    VAL_VIDEO_RECT_T inputRegion;
    VAL_VIDEO_RECT_T outputRegion;
} VAL_WINDOW_INFO_T;

typedef struct {
public:
    UINT16 w = 0;
    UINT16 h = 0;
} VAL_VIDEO_SIZE_T;

typedef struct {
public:
    VAL_VIDEO_WID_T wId;
    std::string planeName;
    VAL_VIDEO_SIZE_T minSizeT;
    VAL_VIDEO_SIZE_T maxSizeT;
} VAL_PLANE_T;

class VAL_Video
{

public:
    virtual ~VAL_Video() = default;
    virtual bool connect(VAL_VIDEO_WID_T wId, VAL_VSC_INPUT_SRC_INFO_T vscInput, VAL_VSC_OUTPUT_MODE_T outputmode,
                         unsigned int *planeId)  = 0;
    virtual bool disconnect(VAL_VIDEO_WID_T wId) = 0;
    virtual bool applyScaling(VAL_VIDEO_WID_T wId, VAL_VIDEO_RECT_T srcInfo, bool adaptive,
                              VAL_VIDEO_RECT_T inputRegion, VAL_VIDEO_RECT_T outputRegion) = 0;
    virtual bool setDualVideo(bool enable) = 0;

    // zOrder.back() has high zorder
    virtual bool setCompositionParams(std::vector<VAL_WINDOW_INFO_T> zOrder) = 0;
    virtual bool setWindowBlanking(VAL_VIDEO_WID_T wId, bool blank, VAL_VIDEO_RECT_T inputRegion,
                                   VAL_VIDEO_RECT_T outputRegion)
    {
        return true;
    };

    // Device Capabilities
    virtual VAL_VIDEO_RECT_T getDisplayResolution() = 0;
    virtual bool getDeviceCapabilities(VAL_VIDEO_SIZE_T &minDownscaleSize, VAL_VIDEO_SIZE_T &maxUpscaleSize) = 0;
    virtual std::vector<VAL_PLANE_T> getVideoPlanes() { return std::vector<VAL_PLANE_T>(); };
    virtual std::vector<VAL_VIDEO_SIZE_T> getSupportedResolutions(uint8_t dispIndex = 0) = 0;
    virtual bool setDisplayResolution(VAL_VIDEO_SIZE_T, uint8_t)                 = 0;
    virtual bool setParam(std::string control, pbnjson::JValue param)            = 0;
    virtual pbnjson::JValue getParam(std::string control, pbnjson::JValue param) = 0;
};

#endif // VAL_VIDEO_API_H
