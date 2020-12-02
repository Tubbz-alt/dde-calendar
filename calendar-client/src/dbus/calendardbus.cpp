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
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "calendardbus.h"

/*
 * Implementation of interface class DCalendarDBus
 */

CalendarDBus::CalendarDBus(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
    qDebug() << service << path;
    //  QDBusConnection::sessionBus().connect(this->service(), this->path(), "org.freedesktop.DBus.Properties",  "PropertiesChanged", "sa{sv}as", this, SLOT(__propertyChanged__(QDBusMessage)));

    CaYearInfo::registerMetaType();
    CaLunarDayInfo::registerMetaType();
    CaLunarMonthInfo::registerMetaType();
    CaSolarMonthInfo::registerMetaType();
    CaHuangLiDayInfo::registerMetaType();
    CaHuangLiMonthInfo::registerMetaType();
}

CalendarDBus::~CalendarDBus()
{
    QDBusConnection::sessionBus().disconnect(service(), path(), "org.freedesktop.DBus.Properties",  "PropertiesChanged",  "sa{sv}as", this, SLOT(propertyChanged(QDBusMessage)));
}

void CaYearInfo::registerMetaType()
{
    qRegisterMetaType<CaYearInfo>();
    qDBusRegisterMetaType<CaYearInfo>();
}

QDebug operator<<(QDebug argument, const CaYearInfo &what)
{
    argument << what.mYear << what.mMonth << what.mDay;

    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const CaYearInfo &what)
{
    argument.beginStructure();
    argument << what.mYear << what.mMonth << what.mDay;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, CaYearInfo &what)
{
    argument.beginStructure();
    argument >> what.mYear >> what.mMonth >> what.mDay;
    argument.endStructure();

    return argument;
}


void CaLunarDayInfo::registerMetaType()
{
    qRegisterMetaType<CaLunarDayInfo>();
    qDBusRegisterMetaType<CaLunarDayInfo>();
}

QDebug operator<<(QDebug argument, const CaLunarDayInfo &what)
{
    argument << what.mGanZhiYear << what.mGanZhiMonth << what.mGanZhiDay;
    argument << what.mLunarMonthName << what.mLunarDayName;
    argument << what.mLunarLeapMonth;
    argument << what.mZodiac << what.mTerm;
    argument << what.mSolarFestival << what.mLunarFestival;
    argument << what.mWorktime;

    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const CaLunarDayInfo &what)
{
    argument.beginStructure();
    argument << what.mGanZhiYear << what.mGanZhiMonth << what.mGanZhiDay;
    argument << what.mLunarMonthName << what.mLunarDayName;
    argument << what.mLunarLeapMonth;
    argument << what.mZodiac << what.mTerm;
    argument << what.mSolarFestival << what.mLunarFestival;
    argument << what.mWorktime;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, CaLunarDayInfo &what)
{
    argument.beginStructure();
    argument >> what.mGanZhiYear >> what.mGanZhiMonth >> what.mGanZhiDay;
    argument >> what.mLunarMonthName >> what.mLunarDayName;
    argument >> what.mLunarLeapMonth;
    argument >> what.mZodiac >> what.mTerm;
    argument >> what.mSolarFestival >> what.mLunarFestival;
    argument >> what.mWorktime;
    argument.endStructure();

    return argument;
}


void CaLunarMonthInfo::registerMetaType()
{
    qRegisterMetaType<CaLunarMonthInfo>();
    qDBusRegisterMetaType<CaLunarMonthInfo>();
}

QDebug operator<<(QDebug argument, const CaLunarMonthInfo &what)
{
    argument << what.mFirstDayWeek << what.mDays;
    argument << what.mCaLunarDayInfo;

    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const CaLunarMonthInfo &what)
{
    argument.beginStructure();
    argument << what.mFirstDayWeek << what.mDays;
    argument << what.mCaLunarDayInfo;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, CaLunarMonthInfo &what)
{
    argument.beginStructure();
    argument >> what.mFirstDayWeek >> what.mDays;
    argument >> what.mCaLunarDayInfo;
    argument.endStructure();

    return argument;
}


void CaSolarMonthInfo::registerMetaType()
{
    qRegisterMetaType<CaSolarMonthInfo>();
    qDBusRegisterMetaType<CaSolarMonthInfo>();
}

QDebug operator<<(QDebug argument, const CaSolarMonthInfo &what)
{
    argument << what.mFirstDayWeek << what.mDays;
    argument << what.mCaYearInfo;

    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const CaSolarMonthInfo &what)
{
    argument.beginStructure();
    argument << what.mFirstDayWeek << what.mDays;
    argument.endStructure();
    argument << what.mCaYearInfo;

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, CaSolarMonthInfo &what)
{
    argument.beginStructure();
    argument >> what.mFirstDayWeek >> what.mDays;
    argument.endStructure();
    argument >> what.mCaYearInfo;

    return argument;
}
#if 1
void CaHuangLiDayInfo::registerMetaType()
{
    qRegisterMetaType<CaHuangLiDayInfo>();
    qDBusRegisterMetaType<CaHuangLiDayInfo>();
}
QDebug operator<<(QDebug argument, const CaHuangLiDayInfo &what)
{
    argument << what.mSuit << what.mAvoid;
    argument << what.mWorktime;
    argument << what.mLunarFestival << what.mSolarFestival;
    argument << what.mTerm << what.mZodiac;
    argument << what.mLunarLeapMonth;
    argument << what.mLunarDayName << what.mLunarMonthName;
    argument << what.mGanZhiDay << what.mGanZhiMonth << what.mGanZhiYear ;
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const CaHuangLiDayInfo &what)
{
    argument.beginStructure();
    argument << what.mSuit << what.mAvoid;
    argument << what.mWorktime;
    argument << what.mLunarFestival << what.mSolarFestival;
    argument << what.mTerm << what.mZodiac;
    argument << what.mLunarLeapMonth;
    argument << what.mLunarDayName << what.mLunarMonthName;
    argument << what.mGanZhiDay << what.mGanZhiMonth << what.mGanZhiYear ;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, CaHuangLiDayInfo &what)
{
    argument.beginStructure();
    argument >> what.mSuit >> what.mAvoid;
    argument >> what.mWorktime;
    argument >> what.mLunarFestival >> what.mSolarFestival;
    argument >> what.mTerm >> what.mZodiac;
    argument >> what.mLunarLeapMonth;
    argument >> what.mLunarDayName >> what.mLunarMonthName;
    argument >> what.mGanZhiDay >> what.mGanZhiMonth >> what.mGanZhiYear ;
    argument.endStructure();
    return argument;
}

void CaHuangLiMonthInfo::registerMetaType()
{
    qRegisterMetaType<CaHuangLiMonthInfo>();
    qDBusRegisterMetaType<CaHuangLiMonthInfo>();
}

QDebug operator<<(QDebug argument, const CaHuangLiMonthInfo &what)
{
    argument << what.mDays << what.mFirstDayWeek;
    argument << what.mCaLunarDayInfo;

    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const CaHuangLiMonthInfo &what)
{
    argument.beginStructure();
    argument << what.mDays << what.mFirstDayWeek;
    argument << what.mCaLunarDayInfo;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, CaHuangLiMonthInfo &what)
{
    argument.beginStructure();
    argument >> what.mDays >> what.mFirstDayWeek;
    argument >> what.mCaLunarDayInfo;
    argument.endStructure();

    return argument;
}
#else
void CaHuangLiDayInfo::registerMetaType()
{
    qRegisterMetaType<CaHuangLiDayInfo>();
    qDBusRegisterMetaType<CaHuangLiDayInfo>();
}
QDebug operator<<(QDebug argument, const CaHuangLiDayInfo &what)
{
    argument << what.mGanZhiYear << what.mGanZhiMonth << what.mGanZhiDay;
    argument << what.mLunarMonthName << what.mLunarDayName;
    argument << what.mLunarLeapMonth;
    argument << what.mZodiac << what.mTerm;
    argument << what.mSolarFestival << what.mLunarFestival;
    argument << what.mWorktime;
    argument << what.mAvoid << what.mSuit ;
    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const CaHuangLiDayInfo &what)
{
    argument.beginStructure();
    argument << what.mGanZhiYear << what.mGanZhiMonth << what.mGanZhiDay;
    argument << what.mLunarMonthName << what.mLunarDayName;
    argument << what.mLunarLeapMonth;
    argument << what.mZodiac << what.mTerm;
    argument << what.mSolarFestival << what.mLunarFestival;
    argument << what.mWorktime;
    argument << what.mAvoid << what.mSuit ;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, CaHuangLiDayInfo &what)
{
    argument.beginStructure();
    argument >> what.mGanZhiYear >> what.mGanZhiMonth >> what.mGanZhiDay;
    argument >> what.mLunarMonthName >> what.mLunarDayName;
    argument >> what.mLunarLeapMonth;
    argument >> what.mZodiac >> what.mTerm;
    argument >> what.mSolarFestival >> what.mLunarFestival;
    argument >> what.mWorktime;
    argument >> what.mAvoid >> what.mSuit ;
    argument.endStructure();
    return argument;
}

void CaHuangLiMonthInfo::registerMetaType()
{
    qRegisterMetaType<CaHuangLiMonthInfo>();
    qDBusRegisterMetaType<CaHuangLiMonthInfo>();
}

QDebug operator<<(QDebug argument, const CaHuangLiMonthInfo &what)
{
    argument << what.mFirstDayWeek << what.mDays;
    argument << what.mCaLunarDayInfo;

    return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const CaHuangLiMonthInfo &what)
{
    argument.beginStructure();
    argument << what.mFirstDayWeek << what.mDays;
    argument << what.mCaLunarDayInfo;
    argument.endStructure();

    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, CaHuangLiMonthInfo &what)
{
    argument.beginStructure();
    argument >> what.mFirstDayWeek >> what.mDays;
    argument >> what.mCaLunarDayInfo;
    argument.endStructure();

    return argument;
}
#endif