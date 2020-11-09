/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
*
* Author:     kongyunzhen <kongyunzhen@uniontech.com>
*
* Maintainer: kongyunzhen <kongyunzhen@uniontech.com>
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
#ifndef CALENDARSCHEDULER_H
#define CALENDARSCHEDULER_H
#include "dbmanager/schedulerdatabase.h"

#include <QObject>

class CalendarScheduler : public QObject
{
    Q_OBJECT
public:
    explicit CalendarScheduler(QObject *parent = nullptr);

    QString GetType(qint64 id);

signals:

public slots:

private:
    SchedulerDatabase *m_database;
};

#endif // CALENDARSCHEDULER_H