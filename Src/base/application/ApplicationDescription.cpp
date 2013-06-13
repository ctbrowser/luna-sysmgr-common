/* @@@LICENSE
*
*      Copyright (c) 2008-2013 LG Electronics, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */


#include "Common.h"

#include <cjson/json.h>

#include "ApplicationDescription.h"


ApplicationDescription::ApplicationDescription()
{
}

ApplicationDescription* ApplicationDescription::fromJsonString(const char* jsonStr, ApplicationDescription* base)
{
    ApplicationDescription* appDesc = base;
    if (!appDesc) appDesc = new ApplicationDescription();
    return ApplicationDescriptionBase::fromJsonString(jsonStr, static_cast<ApplicationDescriptionBase*>(appDesc));
}
