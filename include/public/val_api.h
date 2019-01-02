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

#ifndef VAL_API_H
#define VAL_API_H

// clang-format off
#include "val_video.h"
#include "val_settings.h"
// clang-format on

typedef enum {
    VAL_DEV_UNDEFINED = -1,
    VAL_DEV_RPI,
    VAL_DEV_MAX
} VAL_DEVICE_TYPE_T;

class VAL
{

private:
    static VAL *_instance;

public:
    VAL_Video *video;
    VAL_ControlSettings *controls;

    static VAL *getInstance();

    virtual ~VAL() = default;

    virtual bool initialize()             = 0;
    virtual bool deinitialize()           = 0;
    virtual VAL_DEVICE_TYPE_T getDevice() = 0;
};

#endif // VAL_API_H
