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

#ifndef QITEMMODELBARDATAPROXY_P_H
#define QITEMMODELBARDATAPROXY_P_H

#include "qitemmodelbardataproxy.h"
#include "qbardataproxy_p.h"
#include <QPointer>
#include <QTimer>

QT_DATAVIS3D_BEGIN_NAMESPACE

class QItemModelBarDataProxyPrivate : public QBarDataProxyPrivate
{
    Q_OBJECT
public:
    QItemModelBarDataProxyPrivate(QItemModelBarDataProxy *q);
    virtual ~QItemModelBarDataProxyPrivate();

    void setItemModel(QAbstractItemModel *itemModel);
    void setMapping(QItemModelBarDataMapping *mapping);

public slots:
    void handleColumnsInserted(const QModelIndex & parent, int start, int end);
    void handleColumnsMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationColumn);
    void handleColumnsRemoved(const QModelIndex & parent, int start, int end);
    void handleDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight, const QVector<int> & roles = QVector<int> ());
    void handleLayoutChanged(const QList<QPersistentModelIndex> & parents = QList<QPersistentModelIndex> (), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoLayoutChangeHint);
    void handleModelReset();
    void handleRowsInserted(const QModelIndex & parent, int start, int end);
    void handleRowsMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow);
    void handleRowsRemoved(const QModelIndex & parent, int start, int end);

    void handleMappingChanged();
    void handlePendingResolve();

private:
    void resolveModel();
    QItemModelBarDataProxy *qptr();

    QPointer<QAbstractItemModel> m_itemModel;  // Not owned
    QPointer<QItemModelBarDataMapping> m_mapping; // Not owned
    bool resolvePending;
    QTimer m_resolveTimer;

    friend class QItemModelBarDataProxy;
};

QT_DATAVIS3D_END_NAMESPACE

#endif