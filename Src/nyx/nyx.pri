# @@@LICENSE
#
# Copyright (c) 2010-2013 LG Electronics, Inc.
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
# LICENSE@@@


linux-g++ | linux-g++-64 {
} else {
SOURCES += \
        NyxSensorConnector.cpp \
        NyxInputControl.cpp \
        NyxLedControl.cpp

HEADERS += \
        NyxSensorCommonTypes.h \
        NyxSensorConnector.h \
        NyxInputControl.h \
        NyxLedControl.h

VPATH += Src/input \
         Src/nyx

LIBS += -lnyx

DEFINES += HAS_NYX
}
