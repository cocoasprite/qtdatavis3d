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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the QtDataVis3D API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#include "datavis3dglobal_p.h"
#include "qabstractaxis.h"

#ifndef QABSTRACTAXIS_P_H
#define QABSTRACTAXIS_P_H

QT_DATAVIS3D_BEGIN_NAMESPACE

class QAbstractAxisPrivate : public QObject
{
    Q_OBJECT
public:
    QAbstractAxisPrivate(QAbstractAxis *q, QAbstractAxis::AxisType type);
    virtual ~QAbstractAxisPrivate();

    void setOrientation(QAbstractAxis::AxisOrientation orientation);

protected:
    QAbstractAxis *q_ptr;

    QString m_title;
    QStringList m_labels;
    QAbstractAxis::AxisOrientation m_orientation;
    QAbstractAxis::AxisType m_type;

    friend class QAbstractAxis;
    friend class QValueAxis;
    friend class QCategoryAxis;
};

QT_DATAVIS3D_END_NAMESPACE

#endif // QABSTRACTAXIS_P_H