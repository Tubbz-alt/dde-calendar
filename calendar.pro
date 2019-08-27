######################################################################
# Automatically generated by qmake (3.1) Tue Aug 6 23:56:24 2019
######################################################################
QT += core gui widgets sql svg dbus

TEMPLATE = app
TARGET = deepin-calendar
INCLUDEPATH += .
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget
# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += src/calendardbus.h \
           src/calendarview.h \
           src/calendarwindow.h \
           src/constants.h \
           src/dbuscalendar_adaptor.h \
           src/infoview.h \
           src/spinner.h \
           src/weekindicator.h \
           src/environments.h \
           src/yearview.h \
           src/yearwindow.h \
    src/calendarmainwindow.h \
    src/monthview.h \
    src/monthweekview.h \
    src/monthwindow.h \
    src/monthdayview.h \
    src/schedulecoormanage.h \
    src/dbmanager.h \
    src/schedulestructs.h \
    src/scheduleitem.h \
    src/graphicsview.h \
    src/scheduleview.h \
    src/schceduledlg.h \
    src/schceduledayview.h \
    src/weekheadview.h \
    src/weekview.h \
    src/weekwindow.h \
    src/daymonthview.h \
    src/schcedulesearchview.h \
    src/dayhuangliview.h \
    src/daywindow.h \
    src/verticalscroll.h \
    src/calendartimeeidt.h \
    src/verticalscrolltext.h
SOURCES += src/calendardbus.cpp \
           src/calendarview.cpp \
           src/calendarwindow.cpp \
           src/dbuscalendar_adaptor.cpp \
           src/infoview.cpp \
           src/main.cpp \
           src/spinner.cpp \
           src/weekindicator.cpp \
           src/yearview.cpp \
           src/yearwindow.cpp \
    src/calendarmainwindow.cpp \
    src/monthview.cpp \
    src/monthweekview.cpp \
    src/monthwindow.cpp \
    src/monthdayview.cpp \
    src/dbmanager.cpp \
    src/scheduleitem.cpp \
    src/graphicsview.cpp \
    src/schedulecoormanage.cpp \
    src/scheduleview.cpp \
    src/schceduledlg.cpp \
    src/schceduledayview.cpp \
    src/weekheadview.cpp \
    src/weekview.cpp \
    src/weekwindow.cpp \
    src/daymonthview.cpp \
    src/schcedulesearchview.cpp \
    src/dayhuangliview.cpp \
    src/daywindow.cpp \
    src/verticalscrolltext.cpp \
    src/calendartimeeidt.cpp \
    src/verticalscroll.cpp
RESOURCES += src/resources.qrc
TRANSLATIONS += translations/dde-calendar.ts \
                translations/desktop/desktop_zh_CN.ts
isEmpty(BINDIR):BINDIR=/usr/bin
isEmpty(APPDIR):APPDIR=/usr/share/applications
isEmpty(DSRDIR):DSRDIR=/usr/share/deepin-calendar

# Automating generation .qm files from .ts files
!system($$PWD/translate_generation.sh): error("Failed to generate translation")

target.path = $$INSTROOT$$BINDIR
icon_files.path = $$PREFIX/share/icons/hicolor/scalable/apps/
icon_files.files = $$PWD/images/deepin-calendar.svg

desktop.path = $$INSTROOT$$APPDIR
desktop.files = deepin-calendar.desktop

manual.path = /usr/share/dman/
manual.files = $$PWD/dman/*

translations.path = /usr/share/deepin-calendar/translations/
translations.files = translations/*.qm

INSTALLS += target desktop icon_files translations manual
