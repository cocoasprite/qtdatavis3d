TARGET = datavisualizationqml2
QT += qml quick datavisualization
osx: QT += gui-private
TARGETPATH = QtDataVisualization
IMPORT_VERSION = $$MODULE_VERSION

include($$PWD/designer/designer.pri)

INCLUDEPATH += ../../include \
               ../../include/QtDataVisualization \
               ../datavisualization/engine \
               ../datavisualization/global \
               ../datavisualization/data \
               ../datavisualization/theme \
               ../datavisualization/axis \
               ../datavisualization/input

SOURCES += \
    datavisualizationqml2_plugin.cpp \
    declarativebars.cpp \
    declarativescatter.cpp \
    declarativesurface.cpp \
    abstractdeclarative.cpp \
    colorgradient.cpp \
    declarativeseries.cpp \
    declarativetheme.cpp \
    declarativecolor.cpp \
    declarativescene.cpp \
    declarativerendernode.cpp \
    glstatestore.cpp \
    enumtostringmap.cpp

HEADERS += \
    datavisualizationqml2_plugin.h \
    declarativebars_p.h \
    declarativescatter_p.h \
    declarativesurface_p.h \
    abstractdeclarative_p.h \
    colorgradient_p.h \
    declarativeseries_p.h \
    declarativetheme_p.h \
    declarativecolor_p.h \
    declarativescene_p.h \
    declarativerendernode_p.h \
    glstatestore_p.h \
    enumtostringmap_p.h

OTHER_FILES = qmldir

CONFIG += no_cxx_module

load(qml_plugin)

win32 {
    CONFIG += skip_target_version_ext
    VERSION = $$MODULE_VERSION
    QMAKE_TARGET_PRODUCT = "Qt Data Visualization (Qt $$QT_VERSION)"
    QMAKE_TARGET_DESCRIPTION = "3D Data Visualization QML plugin for Qt."
}

QML_FILES += \
    $$PWD/plugins.qmltypes
