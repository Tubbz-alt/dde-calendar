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
#ifndef SCHEDULEVIEW_H
#define SCHEDULEVIEW_H
#include "schedulestructs.h"
#include "SchecduleRemindWidget.h"

#include <DFrame>

#include <QDate>

DWIDGET_USE_NAMESPACE

class CGraphicsView;
class CAllDayEventWeekView;
class QVBoxLayout;
class CScheduleView : public DFrame
{
    Q_OBJECT
public:
    CScheduleView(QWidget *parent = nullptr, int viewType = 0);
    ~CScheduleView() override;
    void setviewMagin(int left, int top, int right, int bttom);
    void setRange(int w, int h, QDate begin, QDate end);
    void setRange(QDate begin, QDate end);
    void setFirstWeekday(int weekday);
    void setTheMe(int type = 0);
    void setLunarVisible(bool state);
    void setTime(QTime time);
    void setSelectSchedule(const ScheduleDtailInfo &scheduleInfo);
    void updateHigh();
    bool IsDragging();
public slots:
    void slotsupdatescheduleD( QVector<ScheduleDateRangeInfo> &data);
signals:
    void signalsupdatescheduleD(QWidget *w, QDate begin, QDate end);
signals:
    void signalsUpdateShcedule(int id = 0);
    void signalsCurrentScheduleDate(QDate date);
    void signalViewtransparentFrame(int type);
    /**
     * @brief signalAngleDelta      发送滚动信号滚动相对量
     * @param delta     滚动相对量
     */
    void signalAngleDelta(int delta);
public slots:
    void slotPosHours(QVector<int> vPos, QVector<int> vHours, int cuttrnttimetype = 0);
    void setDate(QDate date);
    void slotupdateSchedule();
    void slotDeleteitem();
    void slotCurrentScheduleDate(QDate date);
    void slotScheduleShow(const bool isShow, const ScheduleDtailInfo &out = ScheduleDtailInfo());
    void slotUpdatePaint(const int topM);
    void slotUpdateScene();
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void wheelEvent(QWheelEvent *e) override;
private:
    void initUI();
    void initConnection();
    void updateSchedule();
    void updateAllday();
    int checkDay(int weekday);
    int  scheduleViewHegith();
private:
    CGraphicsView *m_graphicsView = nullptr;
    QVector<int>              m_vPos;
    QVector<int>              m_vHours;
    CAllDayEventWeekView *m_alldaylist = nullptr;
    QVector<ScheduleDateRangeInfo> m_vListSchedule;
    int                       m_leftMagin;
    int                       m_topMagin;
    int                       m_rightmagin = 0;
    qint64 m_TotalDay;
    QDate                     m_currteDate;
    int                       m_firstWeekDay;
    QDate                     m_beginDate;
    QDate                     m_endDate;
    int                       m_viewType = 0;
    int                       m_sMaxNum = 4;
    QColor                    m_linecolor = Qt::lightGray;
    QColor                    m_ALLDayColor = "#303030";
    QColor                    m_timeColor = "#7D7D7D";
    QColor                    m_currenttimecolor = "#F74444";
    int                       m_cuttrnttimetype = 0;
    QVBoxLayout *m_layout = nullptr;
    SchecduleRemindWidget *m_ScheduleRemindWidget = nullptr;
    int m_minTime; //最小高度对应的最小时间
    QFont font;
    const int m_radius = 8;
};

#endif // SCHEDULEVIEW_H
