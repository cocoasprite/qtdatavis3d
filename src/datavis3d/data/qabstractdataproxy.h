/****************************************************************************
**
** Copyright (C) 2013 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the QtDataVis3D module.
**
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
**
****************************************************************************/

#ifndef QABSTRACTDATAPROXY_H
#define QABSTRACTDATAPROXY_H

#include <QtDataVis3D/qdatavis3denums.h>
#include <QObject>
#include <QScopedPointer>

QT_DATAVIS3D_BEGIN_NAMESPACE

class QAbstractDataProxyPrivate;

class QT_DATAVIS3D_EXPORT QAbstractDataProxy : public QObject
{
    Q_OBJECT
    Q_ENUMS(DataType)
    Q_PROPERTY(DataType type READ type)

public:
    enum DataType {
        DataTypeNone = 0,
        DataTypeBar = 1,
        DataTypeMap = 2,
        DataTypeScatter = 4,
        DataTypeSurface = 8
    };

protected:
    explicit QAbstractDataProxy(QAbstractDataProxyPrivate *d);
public:
    virtual ~QAbstractDataProxy();

    DataType type() const;

    // Items use this string to format single item labels, unless custom proxy initializes
    // item labels with something else.
    void setItemLabelFormat(const QString &format);
    QString itemLabelFormat() const;

signals:
    void itemLabelFormatChanged();

protected:
    QScopedPointer<QAbstractDataProxyPrivate> d_ptr;

private:
    Q_DISABLE_COPY(QAbstractDataProxy)
};

QT_DATAVIS3D_END_NAMESPACE

#endif // QABSTRACTDATAPROXY_H