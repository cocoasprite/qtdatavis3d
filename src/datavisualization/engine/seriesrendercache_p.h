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

#ifndef SERIESRENDERCACHE_P_H
#define SERIESRENDERCACHE_P_H

#include "datavisualizationglobal_p.h"
#include "qabstract3dseries_p.h"

QT_DATAVISUALIZATION_BEGIN_NAMESPACE

class Abstract3DRenderer;
class ObjectHelper;

class SeriesRenderCache
{
public:
    SeriesRenderCache();
    virtual ~SeriesRenderCache();

    void populate(QAbstract3DSeries *series, Abstract3DRenderer *renderer);

    // NOTE: Series pointer can only be used to access the series when syncing with controller.
    // It is not guaranteed to be valid while rendering and should only be used as an identifier.
    inline QAbstract3DSeries *series() const { return m_series; }

    inline const QString &itemLabelFormat() const { return m_itemLabelFormat; }
    inline const QAbstract3DSeries::Mesh &mesh() const { return m_mesh; }
    inline ObjectHelper *object() const { return m_object; }

    // TODO: Add other visual elements

protected:
    QAbstract3DSeries *m_series;
    QString m_itemLabelFormat;
    ObjectHelper *m_object;
    QAbstract3DSeries::Mesh m_mesh;
};

QT_DATAVISUALIZATION_END_NAMESPACE

#endif
