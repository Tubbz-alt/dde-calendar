﻿/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     kirigaya <kirigaya@mkacg.com>
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
#include "scheduledatamanage.h"

#include "schedulesdbus.h"

CScheduleDataManage *CScheduleDataManage::m_vscheduleDataManage = new CScheduleDataManage;
CScheduleDataCtrl *CScheduleDataManage::getscheduleDataCtrl()
{
    return m_scheduleDataCtrl;
}

CSchedulesColor CScheduleDataManage::getScheduleColorByType(int type)
{
    CSchedulesColor color;
    color.type = -1;
    for (int i = 0; i < m_vScheduleColor.count(); i++) {
        if (m_vScheduleColor.at(i).type == type) {
            color = m_vScheduleColor.at(i);
            break;
        }
    }
    return color;
}

void CScheduleDataManage::setSearchResult(QVector<ScheduleDateRangeInfo> &vData)
{
    m_vScheduleInfo = vData;
}

bool CScheduleDataManage::getSearchResult(ScheduleDtailInfo info)
{
    for (int i = 0; i < m_vScheduleInfo.size(); i++) {
        QVector<ScheduleDtailInfo> &scheduleInfolist = m_vScheduleInfo[i].vData;
        for (int j = 0; j < scheduleInfolist.count(); j++) {
            if (scheduleInfolist.at(j).id == info.id) {
                return true;
            }
        }
    }
    return false;
}

void CScheduleDataManage::setTheMe(int type)
{
    m_theme = type;
    m_vScheduleColor.clear();
    if (type == 0 || type == 1) {
        CSchedulesColor workC;
        workC.type = 1;
        workC.gradientFromC = "#FBCEB7";
        workC.gradientFromC.setAlphaF(0.7);
        workC.gradientToC = "#FA9D9A";
        workC.gradientToC.setAlphaF(0.7);
        workC.Purecolor = "#F85566";
        workC.Purecolor.setAlphaF(0.2);
        workC.shadowcolor = "#FB2525";
        workC.shadowcolor.setAlphaF(0.5);
        workC.textColor = "#000000";
        workC.timeColor = "#B54A4B";
        workC.hightlightgradientFromC = "#FFD0B8";
        workC.hightlightgradientToC = "#FF908D";
        QColor workP("#F9AEB8");
        //workP.setAlphaF(0.8);
        workC.hightlightPurecolor = workP;

        workC.hovergradientFromC = "#FFD0B8";
        workC.hovergradientFromC.setAlphaF(0.95);
        workC.hovergradientToC = "#FF9D9A";
        workC.hovergradientToC.setAlphaF(0.95);
        QColor workhP("#FFB6BD");
        workP.setAlphaF(0.8);
        workC.hoverPurecolor = workhP;
        m_vScheduleColor.append(workC);

        CSchedulesColor lifeC;
        lifeC.type = 2;
        lifeC.gradientFromC = "#B7E6FB";
        lifeC.gradientFromC.setAlphaF(0.7);
        lifeC.gradientToC = "#D4FFB3";
        lifeC.gradientToC.setAlphaF(0.7);
        lifeC.Purecolor = "#6FFF00";
        lifeC.Purecolor.setAlphaF(0.2);
        lifeC.shadowcolor = "#82D245";
        lifeC.textColor = "#000000";
        lifeC.timeColor = "#53A316";
        lifeC.hightlightgradientFromC = "#9AE5FF";
        lifeC.hightlightgradientToC = "#C7FF94";
        QColor lifeP("#C7FF94");
        //lifeP.setAlphaF(0.8);
        lifeC.hightlightPurecolor = lifeP;

        lifeC.hovergradientFromC = "#A8E9FF";
        lifeC.hovergradientToC = "#D5FFAF";
        lifeC.hovergradientFromC.setAlphaF(0.95);
        lifeC.hovergradientToC.setAlphaF(0.95);
        QColor lifehP("#C4FF98");
        lifehP.setAlphaF(0.8);
        lifeC.hoverPurecolor = lifehP;
        m_vScheduleColor.append(lifeC);

        CSchedulesColor otherC;
        otherC.type = 3;
        otherC.gradientFromC = "#FBE9B7";
        otherC.gradientFromC.setAlphaF(0.7);
        otherC.gradientToC = "#DFB3FF";
        otherC.gradientToC.setAlphaF(0.7);
        otherC.Purecolor = "#D191FF";
        otherC.Purecolor.setAlphaF(0.2);
        otherC.shadowcolor = "#BA60FA";
        otherC.textColor = "#000000";
        otherC.timeColor = "#8548B1";
        otherC.hightlightgradientFromC = "#FFE8AC";
        otherC.hightlightgradientToC = "#FBA5FF";
        QColor otherP("#EAC4FF");
        //otherP.setAlphaF(0.8);
        otherC.hightlightPurecolor = otherP;

        otherC.hovergradientFromC = "#FFE8AC";
        otherC.hovergradientToC = "#E2A5FF";
        otherC.hovergradientFromC.setAlphaF(0.95);
        otherC.hovergradientToC.setAlphaF(0.95);
        QColor otherhP("#E6C5FF");
        otherhP.setAlphaF(0.8);
        otherC.hoverPurecolor = otherhP;
        m_vScheduleColor.append(otherC);
    } else if (type == 2) {
        CSchedulesColor workC;
        workC.type = 1;
        workC.gradientFromC = "#965A26";
        workC.gradientToC = "#8B2521";
        workC.gradientToC.setAlphaF(0.7);
        workC.gradientFromC.setAlphaF(0.7);
        workC.Purecolor = "#F85566";
        workC.Purecolor.setAlphaF(0.1);
        workC.shadowcolor = "#FB2525";
        workC.shadowcolor.setAlphaF(0.5);
        workC.textColor = "#C0C6D4";
        workC.timeColor = "#B54A4B";
        workC.hightlightgradientToC = "#992D2A";
        workC.hightlightgradientFromC = "#8B521F";
        QColor workP("#77373E");
        workP.setAlphaF(0.8);
        workC.hightlightPurecolor = workP;

        workC.hovergradientFromC = "#965A26";
        workC.hovergradientToC = "#8B2521";
        workC.hovergradientFromC.setAlphaF(0.95);
        workC.hovergradientToC.setAlphaF(0.95);
        QColor workhP("#F85566");
        workhP.setAlphaF(0.2);
        workC.hoverPurecolor = workhP;

        m_vScheduleColor.append(workC);

        CSchedulesColor lifeC;
        lifeC.type = 2;
        lifeC.gradientFromC = "#2D6883";
        lifeC.gradientToC = "#5D7D44";
        lifeC.gradientToC.setAlphaF(0.7);
        lifeC.gradientFromC.setAlphaF(0.7);
        lifeC.Purecolor = "#59F88D";
        lifeC.Purecolor.setAlphaF(0.1);
        lifeC.shadowcolor = "#25FA6B";
        lifeC.shadowcolor.setAlphaF(0.5);
        lifeC.textColor = "#C0C6D4";
        lifeC.timeColor = "#38A35B";
        lifeC.hightlightgradientFromC = "#2D6883";
        lifeC.hightlightgradientToC = "#5D7D44";
        QColor lifeP("#337044");
        lifeP.setAlphaF(0.8);
        lifeC.hightlightPurecolor = lifeP;

        lifeC.hovergradientFromC = "#2D6883";
        lifeC.hovergradientToC = "#5D7D44";
        lifeC.hovergradientFromC.setAlphaF(0.95);
        lifeC.hovergradientToC.setAlphaF(0.95);
        QColor lifehP("#59F88D");
        lifehP.setAlphaF(0.2);
        lifeC.hoverPurecolor = lifehP;
        m_vScheduleColor.append(lifeC);

        CSchedulesColor otherC;
        otherC.type = 3;
        otherC.gradientFromC = "#8C4E2C";
        otherC.gradientToC = "#7D37AF";
        otherC.gradientToC.setAlphaF(0.7);
        otherC.gradientFromC.setAlphaF(0.7);
        otherC.Purecolor = "#C155F8";
        otherC.Purecolor.setAlphaF(0.1);
        otherC.shadowcolor = "#BE3DFF";
        otherC.shadowcolor.setAlphaF(0.5);
        otherC.textColor = "#C0C6D4";
        otherC.timeColor = "#9857C8";
        otherC.hightlightgradientFromC = "#8C4E2C";
        otherC.hightlightgradientToC = "#803BAE";
        QColor otherP("#613776");
        otherP.setAlphaF(0.8);
        otherC.hightlightPurecolor = otherP;

        otherC.hovergradientFromC = "#8C4E2C";
        otherC.hovergradientToC = "#7D37AF";
        otherC.hovergradientFromC.setAlphaF(0.95);
        otherC.hovergradientToC.setAlphaF(0.95);
        QColor otherhP("#C155F8");
        otherhP.setAlphaF(0.2);
        otherC.hoverPurecolor = otherhP;
        m_vScheduleColor.append(otherC);
    }
}

CScheduleDataManage *CScheduleDataManage::getScheduleDataManage()
{
    return m_vscheduleDataManage;
}

void CScheduleDataManage::clear()
{
    delete m_scheduleDataCtrl;
}

CScheduleDataManage::CScheduleDataManage ()
{
    m_scheduleDataCtrl = new CScheduleDataCtrl;
    CSchedulesColor workC;
    workC.type = 1;
    workC.gradientFromC = "#FBCEB7";
    workC.gradientToC = "#FA9D9A";
    workC.Purecolor = "#F85566";
    workC.Purecolor.setAlphaF(0.2);
    workC.shadowcolor = "#FB2525";
    workC.shadowcolor.setAlphaF(0.5);
    workC.textColor = "#000000";
    workC.timeColor = "#B54A4B";
    m_vScheduleColor.append(workC);

    CSchedulesColor lifeC;
    lifeC.type = 2;
    lifeC.gradientFromC = "#B7E6FB";
    lifeC.gradientToC = "#D4FFB3";
    lifeC.Purecolor = "#6FFF00";
    lifeC.Purecolor.setAlphaF(0.2);
    lifeC.shadowcolor = "#82D245";
    lifeC.textColor = "#000000";
    lifeC.timeColor = "#53A316";
    m_vScheduleColor.append(lifeC);

    CSchedulesColor otherC;
    otherC.type = 3;
    otherC.gradientFromC = "#FBE9B7";
    otherC.gradientToC = "#DFB3FF";
    otherC.Purecolor = "#D191FF";
    otherC.Purecolor.setAlphaF(0.2);
    otherC.shadowcolor = "#BA60FA";
    workC.textColor = "#000000";
    workC.timeColor = "#8548B1";
    m_vScheduleColor.append(otherC);
}

CScheduleDataManage::~CScheduleDataManage()
{

}

CScheduleDataCtrl::CScheduleDataCtrl()
{
    qRegisterMetaType<QVector<ScheduleDateRangeInfo>>("QVector<ScheduleDateRangeInfo>");
    m_dbus = new CSchedulesDBus("com.deepin.daemon.Calendar",
                                "/com/deepin/daemon/Calendar/Scheduler",
                                QDBusConnection::sessionBus(), this);
    m_scheduleDateCache = nullptr;

    if (!m_scheduleDateCache)
        m_scheduleDateCache = new QMap<QDate, ScheduleDateRangeInfo>;
    m_thread = new CDataProcessThread(m_dbus);
    connect(m_thread, &CDataProcessThread::signalsDataProcess, this, &CScheduleDataCtrl::slotDataProcess);
}

CScheduleDataCtrl::~CScheduleDataCtrl()
{
    delete  m_scheduleDateCache;
    delete  m_dbus;
    delete m_thread;
}



qint64 CScheduleDataCtrl::addSchedule(const ScheduleDtailInfo &scheduledate)
{
    clearData();
    return m_dbus->CreateJob(scheduledate);
}

bool CScheduleDataCtrl::getScheduleInfoById(int id, ScheduleDtailInfo &out)
{
    return m_dbus->GetJob(id, out);
}

bool CScheduleDataCtrl::getScheduleInfo(const QDate bdate, const QDate edate, QVector<ScheduleDateRangeInfo> &out)
{
    return m_dbus->GetJobs(bdate.year(), bdate.month(), bdate.day(), edate.year(), edate.month(), edate.day(), out);
}

bool CScheduleDataCtrl::queryScheduleInfo(QString key, QDateTime starttime, QDateTime endtime, QVector<ScheduleDateRangeInfo> &out)
{
    return m_dbus->QueryJobs(key, starttime, endtime, out);
}

bool CScheduleDataCtrl::queryScheduleInfo(QString key, QDateTime starttime, QDateTime endtime, QString &out)
{
    return m_dbus->QueryJobs(key, starttime, endtime, out);
}

bool CScheduleDataCtrl::updateScheduleInfo(const ScheduleDtailInfo &scheduledate)
{
    clearData();
    return m_dbus->UpdateJob(scheduledate);
}

bool CScheduleDataCtrl::deleteScheduleInfoById(int id)
{
    clearData();
    return m_dbus->DeleteJob(id);
}

bool CScheduleDataCtrl::GetType(qint64 jobId, ScheduleType &out)
{
    while (m_thread->isRunning());
    return m_dbus->GetType(jobId, out);
}

void CScheduleDataCtrl::slotupdatescheduleD(QWidget *w, QDate begin, QDate end)
{
    m_currentWidget = w;
    m_begindate = begin;
    m_enddate = end;
    m_thread->DataProcessStart(begin, end);
}

void CScheduleDataCtrl::slotDataProcess(QVector<ScheduleDateRangeInfo> out)
{
    emit signalsupdatescheduleD(m_currentWidget, out);
}

void CScheduleDataCtrl::clearData()
{
    while (m_thread->isRunning());
    m_scheduleDateCache->clear();
}

CDataProcessThread::CDataProcessThread(CSchedulesDBus *_DataManage)
{
    m_DataManage = _DataManage;
    m_stopFlag = false;
}

CDataProcessThread::~CDataProcessThread()
{
    //防止未运行完
    m_mutex.lock();
    m_stopFlag = true;
    m_mutex.unlock();
    //是否允许
    while (isRunning()) {}
}

void CDataProcessThread::DataProcessStart(QDate begin, QDate end)
{
    m_mutex.lock();
    this->m_stopFlag = true;
    this->m_begindate = begin;
    this->m_enddate = end;
    m_mutex.unlock();

    while (isRunning()) {}
    m_mutex.lock();
    m_stopFlag = false;
    m_mutex.unlock();

    start(QThread::NormalPriority);
}

void CDataProcessThread::run()
{
    forever {
        //运行
        m_mutex.lock();
        QDate bdate =  m_begindate;
        QDate edate = m_enddate;
        bool t_stopFlag = m_stopFlag;
        m_mutex.unlock();
        if (t_stopFlag)
            return;
        QVector<ScheduleDateRangeInfo> out;
        bool flag = m_DataManage->GetJobs(bdate.year(), bdate.month(), bdate.day(), edate.year(), edate.month(), edate.day(), out);
        if (!flag) return;
        emit signalsDataProcess(out);
        break;
    }
}
