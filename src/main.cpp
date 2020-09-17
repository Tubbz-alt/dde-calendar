/*
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

#include "environments.h"

#include <QFile>
#include <QDebug>
#include <QDesktopWidget>
#include <QDBusConnection>
#include <DApplication>
#include <DLog>
#include <DHiDPIHelper>
#include "calendarmainwindow.h"
//#include "monthwindow.h"
#include "yearwindow.h"
#include "exportedinterface.h"
#include "configsettings.h"
DWIDGET_USE_NAMESPACE
DCORE_USE_NAMESPACE
/**********************复制部分**************************/
static QString g_appPath;//全局路径
/**********************复制部分**************************/

/**********************复制部分**************************/
//获取配置文件主题类型，并重新设置
DGuiApplicationHelper::ColorType getThemeTypeSetting()
{
    //需要找到自己程序的配置文件路径，并读取配置，这里只是用home路径下themeType.cfg文件举例,具体配置文件根据自身项目情况
    QString t_appDir = g_appPath + QDir::separator() + "themetype.cfg";
    QFile t_configFile(t_appDir);

    t_configFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray t_readBuf = t_configFile.readAll();
    int t_readType = QString(t_readBuf).toInt();

    //获取读到的主题类型，并返回设置
    switch (t_readType) {
    case 0:
        // 跟随系统主题
        return DGuiApplicationHelper::UnknownType;
    case 1:
//        浅色主题
        return DGuiApplicationHelper::LightType;

    case 2:
//        深色主题
        return DGuiApplicationHelper::DarkType;
    default:
        // 跟随系统主题
        return DGuiApplicationHelper::UnknownType;
    }

}

/**********************复制部分**************************/

/**********************复制部分**************************/
//保存当前主题类型配置文件
void saveThemeTypeSetting(int type)
{
    //需要找到自己程序的配置文件路径，并写入配置，这里只是用home路径下themeType.cfg文件举例,具体配置文件根据自身项目情况
    QString t_appDir = g_appPath + QDir::separator() + "themetype.cfg";
    QFile t_configFile(t_appDir);

    t_configFile.open(QIODevice::WriteOnly | QIODevice::Text);
    //直接将主题类型保存到配置文件，具体配置key-value组合根据自身项目情况
    QString t_typeStr = QString::number(type);
    t_configFile.write(t_typeStr.toUtf8());
    t_configFile.close();
}

QString GetStyleSheetContent()
{
    QFile file(":/resources/dde-calendar.qss");
    bool result = file.open(QFile::ReadOnly);
    if (result) {
        QString content(file.readAll());
        file.close();
        return content;
    } else {
        return "";
    }
}

QRect PrimaryRect()
{
    QDesktopWidget *w = QApplication::desktop();
    return w->screenGeometry(w->primaryScreen());
}
#include "schedulesdbus.h"
int main(int argc, char *argv[])
{
    //DApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    //为了解决应用打开不在桌面正中心，还有没有帮助等问题，
    qputenv("QT_WAYLAND_SHELL_INTEGRATION","kwayland-shell");
    // DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    g_appPath = QDir::homePath() + QDir::separator() + "." + qApp->applicationName();
    QDir t_appDir;
    t_appDir.mkpath(g_appPath);
    a.setOrganizationName("deepin");
    a.setApplicationName("dde-calendar");
    a.loadTranslator();
    //QLocale::setDefault(QLocale(QLocale::C, QLocale::UnitedStates));
    a.setApplicationVersion(DApplication::buildVersion("1.1"));
    //QList<QLocale> localeFallback = QList<QLocale>() << QLocale::system();
    // meta information that necessary to create the about dialog.
    a.setProductName(QApplication::translate("CalendarWindow", "Calendar"));
    QIcon t_icon = QIcon::fromTheme("dde-calendar");
    //a.setProductIcon(DHiDPIHelper::loadNxPixmap(":/resources/icon/dde-logo.svg"));
    a.setProductIcon(t_icon);
    a.setApplicationDescription(QApplication::translate("CalendarWindow", "Calendar is a tool to view dates, and also a smart daily planner to schedule all things in life. "));
    a.setApplicationAcknowledgementPage("https://www.deepin.org/acknowledgments/dde-calendar");
    //a.setTheme("light");
    //a.setStyle("chameleon");
    static const QDate buildDate = QLocale( QLocale::English ).toDate( QString(__DATE__).replace("  ", " 0"), "MMM dd yyyy");
    QString t_date = buildDate.toString("MMdd");
    // Version Time
    a.setApplicationVersion(DApplication::buildVersion(t_date));

    if (!a.setSingleInstance("dde-calendar", DApplication::UserScope)) {
        qDebug() << "there's an dde-calendar instance running.";
        QProcess::execute("dbus-send --print-reply --dest=com.deepin.Calendar "
                          "/com/deepin/Calendar com.deepin.Calendar.RaiseWindow");

        return 0;
    }
    a.setAutoActivateWindows(true);
    CConfigSettings::init();
    // set theme
    bool isOk = false;
    int viewtype = CConfigSettings::value("base.view").toInt(&isOk);
    if (!isOk)
        viewtype = 2;
    DLogManager::registerConsoleAppender();
    DLogManager::registerFileAppender();
    // 应用已保存的主题设置
    DGuiApplicationHelper::instance()->setPaletteType(getThemeTypeSetting());

    Calendarmainwindow ww;
    ExportedInterface einterface(&ww);
    einterface.registerAction("CREATE", "create a new schedule");
    einterface.registerAction("VIEW", "check a date on calendar");
    einterface.registerAction("QUERY", "find a schedule information");
    einterface.registerAction("CANCEL", "cancel a schedule");
    QDBusConnection dbus = QDBusConnection::sessionBus();
    dbus.registerService("com.deepin.Calendar");
    dbus.registerObject("/com/deepin/Calendar", &ww);
    //ww.setDate(QDate::currentDate());
    ww.slotTheme(getThemeTypeSetting());
    ww.viewWindow(viewtype, QDateTime::currentDateTime());
    //ww.move(PrimaryRect().center() - ww.geometry().center());
    ww.show();

    //QDBusConnection dbus = QDBusConnection::sessionBus();
    //dbus.registerService("com.deepin.Calendar");
    //dbus.registerObject("/com/deepin/Calendar", &ww);
    //监听当前应用主题切换事件
    QObject::connect(DGuiApplicationHelper::instance(), &DGuiApplicationHelper::paletteTypeChanged,
    [] (DGuiApplicationHelper::ColorType type) {
        qDebug() << type;
        // 保存程序的主题设置  type : 0,系统主题， 1,浅色主题， 2,深色主题
        saveThemeTypeSetting(type);
        DGuiApplicationHelper::instance()->setPaletteType(type);
    });
//    if (dbus.registerService("com.deepin.Calendar"), QDBusConnectionInterface::ReplaceExistingService, QDBusConnectionInterface::AllowReplacement) {


//        return a.exec();
//    }
    return a.exec();
}
