/*
 * Copyright (C) 2015 ~ 2018 Deepin Technology Co., Ltd.
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

/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DCalendarDBus -p dcalendardbus com.deepin.dataserver.Calendar.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef CreatOrParSchedule_H
#define CALENDARDBUS_H

#include "schedulestructs.h"

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QDebug>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

/*
 * Proxy class for interface com.deepin.dataserver.Calendar
 */
class CreatOrParSchedule
{

public:
    static QString createScheduleDtailInfojson(const ScheduleDtailInfo &info);
    static QString createScheduleTypejson(const ScheduleType &info);
    static ScheduleType parsingScheduleTypejson(QJsonObject &object);
    static ScheduleDtailInfo parsingScheduleDtailInfojsonID(QJsonObject &obj);
    static QString createScheduleRRule(const ScheduleDtailInfo &info);
    static void parsingScheduleRRule(QString str, ScheduleDtailInfo &info);
    static QString createScheduleRemind(const ScheduleDtailInfo &info);
    static void parsingScheduleRemind(QString str, ScheduleDtailInfo &info);
    static QString toconvertData(QDateTime date);
    static QDateTime fromconvertData(QString str);
    static QString toconvertIGData(QDateTime date);
    static QDateTime fromconvertiIGData(QString str);
    static  QString CreateJob(const ScheduleDtailInfo &info);
    static bool GetJob(QString str, ScheduleDtailInfo &out);
private:
    CreatOrParSchedule();
    ~CreatOrParSchedule();
};
#endif