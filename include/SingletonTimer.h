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




#ifndef SINGLETONTIMER_H
#define SINGLETONTIMER_H

#include "Common.h"

#include <glib.h>
#include <stdint.h>

struct TimerHandle;
struct TimerSource;

typedef void (*TimerCallback)(void* userArg);

class SingletonTimer
{
public:

	SingletonTimer(GMainLoop* loop);
	~SingletonTimer();

	TimerHandle* create(TimerCallback callback, void* userArg);
	void         fire(TimerHandle* timer, uint64_t timeInMs);
	void         ref(TimerHandle* timer);
	void         deref(TimerHandle* timer);

	static uint64_t currentTime();
	
	// Internal functions. don't use
	static gboolean timerPrepare(GSource* source, gint* timeout);
	static gboolean timerCheck(GSource* source);
	static gboolean timerDispatch(GSource* source, GSourceFunc callback, gpointer userData);
	
private:

	void destroy(TimerHandle* handle);
	
	GMainLoop*   m_loop;
	TimerSource* m_source;
	GList*       m_activeList;

private:

	SingletonTimer(const SingletonTimer&);
	SingletonTimer& operator=(const SingletonTimer&);
};

#endif /* SINGLETONTIMER_H */
