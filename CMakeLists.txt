# Copyright (c) 2017-2019 LG Electronics, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 2.8.7)

project(videooutput-adaptation-layer-api CXX)

include(webOS/webOS)
webos_modules_init(1 0 0 QUALIFIER RC7)
webos_component(1 0 0)

# Enable C++11 support (still gcc 4.6 so can't use -std=c++11)
webos_add_compiler_flags(ALL -std=c++0x)

include(FindPkgConfig)
include_directories(include/public)

install(DIRECTORY "include/public/" DESTINATION @WEBOS_INSTALL_INCLUDEDIR@/val FILES_MATCHING PATTERN "*.h" PATTERN ".*" EXCLUDE)
webos_build_pkgconfig(files/pkgconfig/videooutput-adaptation-layer-api)

# The following line can be removed once it has been added to cmake-modules-webos:
webos_add_compiler_flags(DEBUG -DWEBOS_DEBUG=1)

webos_config_build_doxygen(doc Doxyfile)
