/****************************************************************************
**
** Copyright (C) 2013 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the QtDataVisualization module.
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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the QtDataVisualization API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef QHEIGHTMAPSURFACEDATAPROXY_P_H
#define QHEIGHTMAPSURFACEDATAPROXY_P_H

#include "qheightmapsurfacedataproxy.h"
#include "qsurfacedataproxy_p.h"
#include <QTimer>

QT_DATAVISUALIZATION_BEGIN_NAMESPACE

class QHeightMapSurfaceDataProxyPrivate : public QSurfaceDataProxyPrivate
{
    Q_OBJECT

public:
    QHeightMapSurfaceDataProxyPrivate(QHeightMapSurfaceDataProxy *q);
    virtual ~QHeightMapSurfaceDataProxyPrivate();

private:
    QHeightMapSurfaceDataProxy *qptr();
    void handlePendingResolve();

    QImage m_heightMap;
    QString m_heightMapFile;
    QTimer m_resolveTimer;

    friend class QHeightMapSurfaceDataProxy;
};

QT_DATAVISUALIZATION_END_NAMESPACE

#endif