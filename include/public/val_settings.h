// Copyright (c) 2017-2018 LG Electronics, Inc.
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

#ifndef VAL_CONTROLS_API_H
#define VAL_CONTROLS_API_H

#include <string>

#define SHARPNESS_Control "sharpness"
#define PQ_Control "pq"
#define BLACK_LEVEL_Control "black_level"

typedef enum {
    VAL_VPQ_INPUT_ATV = 0,     ///< analog rf
    VAL_VPQ_INPUT_AV,          ///< cvbs,svideo
    VAL_VPQ_INPUT_SCARTRGB,    ///< scart-rgb
    VAL_VPQ_INPUT_COMP,        ///< component
    VAL_VPQ_INPUT_RGB_PC,      ///< rgb-pc
    VAL_VPQ_INPUT_HDMI_TV,     ///< hdmi non-pc(hdmi-av,dvi-dtv,mcam)
    VAL_VPQ_INPUT_HDMI_PC,     ///< hdmi pc(dvi-pc)
    VAL_VPQ_INPUT_DTV,         ///< digital rf
    VAL_VPQ_INPUT_PICWIZ,      ///< dtv pic wiz
    VAL_VPQ_INPUT_PICTEST,     ///< dtv pic test
    VAL_VPQ_INPUT_MEDIA_MOVIE, ///< divx, cp-divx
    VAL_VPQ_INPUT_MEDIA_PHOTO, ///< photo, cp-photo
    VAL_VPQ_INPUT_CAMERA,      ///< vcs
    VAL_VPQ_INPUT_PVR_DTV,     ///< pvr dtv
    VAL_VPQ_INPUT_PVR_ATV,     ///< pvr atv
    VAL_VPQ_INPUT_PVR_AV,      ///< pvr av,scart-rgb
    VAL_VPQ_INPUT_MAX          ///< max num
} VAL_VPQ_INPUT_T;

class VAL_ControlSettings
{

public:
    virtual ~VAL_ControlSettings() = default;
    virtual bool configureVideoSettings(const std::string ctrl, const VAL_VIDEO_WID_T winID, const int32_t[]) = 0;
};

#endif // VAL_CONTROLS_API_H
