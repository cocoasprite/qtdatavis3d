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

#include "qcategoryaxis.h"
#include "qabstractaxis_p.h"
#include "qbardataitem.h"

#ifndef QCATEGORYAXIS_P_H
#define QCATEGORYAXIS_P_H

QT_DATAVIS3D_BEGIN_NAMESPACE

class QCategoryAxisPrivate : public QAbstractAxisPrivate
{
    Q_OBJECT

public:
    QCategoryAxisPrivate(QCategoryAxis *q);
    virtual ~QCategoryAxisPrivate();
};

QT_DATAVIS3D_END_NAMESPACE

#endif // QCATEGORYAXIS_P_H