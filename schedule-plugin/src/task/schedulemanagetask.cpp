/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
*
* Author:     uniontech  <uniontech@uniontech.com>
*
* Maintainer: uniontech  <chenhaifeng@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "schedulemanagetask.h"

#include "../dbus/schedulesdbus.h"
#include "../globaldef.h"
#include "../widget/schedulelistwidget.h"
#include "../data/createjsondata.h"
#include "../data/queryjsondata.h"
#include "../data/canceljsondata.h"
#include "../data/changejsondata.h"
#include "../widget/viewschedulewidget.h"
#include "createscheduletask.h"
#include "queryscheduletask.h"
#include "cancelscheduletask.h"
#include "changescheduletask.h"

DWIDGET_USE_NAMESPACE

ScheduleManageTask *ScheduleManageTask::m_scheduleManageTask = nullptr;

ScheduleManageTask::ScheduleManageTask(QObject *parent)
    : QObject(parent)
    , m_dbus(new CSchedulesDBus(DBUS_SERVICE, DBUS_PATCH, QDBusConnection::sessionBus(), this))
{
    m_scheduleTaskMap[JSON_CREATE] = new createScheduleTask(m_dbus);
    m_scheduleTaskMap[JSON_VIEW] = new queryScheduleTask(m_dbus);
    m_scheduleTaskMap[JSON_CANCEL] = new cancelScheduleTask(m_dbus);
    m_scheduleTaskMap[JSON_CHANGE] = new changeScheduleTask(m_dbus);

    QMap<QString, scheduleBaseTask *>::Iterator inter = m_scheduleTaskMap.begin();
    for (; inter != m_scheduleTaskMap.end(); ++inter) {
        scheduleBaseTask *task = inter.value();
        connect(task, &scheduleBaseTask::signaleSendMessage, this, &ScheduleManageTask::signaleSendMessage);
    }
}

ScheduleManageTask::~ScheduleManageTask()
{
    QMap<QString, scheduleBaseTask *>::Iterator inter = m_scheduleTaskMap.begin();
    for (; inter != m_scheduleTaskMap.end(); ++inter) {
        scheduleBaseTask *task = inter.value();
        delete task;
    }
    m_scheduleTaskMap.clear();
}

ScheduleManageTask *ScheduleManageTask::getInstance()
{
    if (m_scheduleManageTask == nullptr) {
        m_scheduleManageTask = new ScheduleManageTask();
    }
    return m_scheduleManageTask;
}

void ScheduleManageTask::releaseInstance()
{
    if (m_scheduleManageTask != nullptr) {
        delete m_scheduleManageTask;
        m_scheduleManageTask = nullptr;
    }
}

void ScheduleManageTask::process(semanticAnalysisTask &semanticTask)
{
    if (m_scheduleTaskMap.contains(semanticTask.Intent())) {
        if (m_preScheduleTask != m_scheduleTaskMap[semanticTask.Intent()]) {
            if (m_preScheduleTask != nullptr)
                m_preScheduleTask->InitState(nullptr, true);
            m_preScheduleTask = m_scheduleTaskMap[semanticTask.Intent()];
        }
    }
    if (m_preScheduleTask == nullptr) {
        Reply reply;
        REPLY_ONLY_TTS(reply, G_ERR_TTS, G_ERR_TTS, true);
        setReply(reply);
    } else {
        setReply(m_preScheduleTask->SchedulePress(semanticTask));
    }
}

void ScheduleManageTask::slotReceivce(QVariant data, Reply *reply)
{
    Q_UNUSED(data);
    Q_UNUSED(reply);
}

Reply ScheduleManageTask::getReply() const
{
    return m_Reply;
}

void ScheduleManageTask::setReply(const Reply &Reply)
{
    m_Reply = Reply;
}
