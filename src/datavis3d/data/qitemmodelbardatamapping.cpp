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

#include "qitemmodelbardatamapping_p.h"

QT_DATAVIS3D_BEGIN_NAMESPACE

QItemModelBarDataMapping::QItemModelBarDataMapping()
    : QObject(0),
      d_ptr(new QItemModelBarDataMappingPrivate(this))
{
}

QItemModelBarDataMapping::QItemModelBarDataMapping(const QItemModelBarDataMapping &other)
    : QObject(0),
      d_ptr(new QItemModelBarDataMappingPrivate(this))
{
    operator=(other);
}

QItemModelBarDataMapping::QItemModelBarDataMapping(const QString &valueRole)
    : QObject(0),
      d_ptr(new QItemModelBarDataMappingPrivate(this))
{
    d_ptr->m_valueRole = valueRole;
}

QItemModelBarDataMapping::QItemModelBarDataMapping(const QString &rowRole,
                                                   const QString &columnRole,
                                                   const QString &valueRole,
                                                   const QStringList &rowCategories,
                                                   const QStringList &columnCategories)
    : QObject(0),
      d_ptr(new QItemModelBarDataMappingPrivate(this))
{
    d_ptr->m_rowRole = rowRole;
    d_ptr->m_columnRole = columnRole;
    d_ptr->m_valueRole = valueRole;
    d_ptr->m_rowCategories = rowCategories;
    d_ptr->m_columnCategories = columnCategories;
}

QItemModelBarDataMapping::~QItemModelBarDataMapping()
{
}

QItemModelBarDataMapping &QItemModelBarDataMapping::operator=(const QItemModelBarDataMapping &other)
{
    d_ptr->m_rowRole = other.d_ptr->m_rowRole;
    d_ptr->m_columnRole = other.d_ptr->m_columnRole;
    d_ptr->m_valueRole = other.d_ptr->m_valueRole;
    d_ptr->m_rowCategories = other.d_ptr->m_rowCategories;
    d_ptr->m_columnCategories = other.d_ptr->m_columnCategories;

    return *this;
}

void QItemModelBarDataMapping::setRowRole(const QString &role)
{
    d_ptr->m_rowRole = role;
    emit mappingChanged();
}

QString QItemModelBarDataMapping::rowRole() const
{
    return d_ptr->m_rowRole;
}

void QItemModelBarDataMapping::setColumnRole(const QString &role)
{
    d_ptr->m_columnRole = role;
    emit mappingChanged();
}

QString QItemModelBarDataMapping::columnRole() const
{
    return d_ptr->m_columnRole;
}

void QItemModelBarDataMapping::setValueRole(const QString &role)
{
    d_ptr->m_valueRole = role;
    emit mappingChanged();
}

QString QItemModelBarDataMapping::valueRole() const
{
    return d_ptr->m_valueRole;
}

void QItemModelBarDataMapping::setRowCategories(const QStringList &categories)
{
    d_ptr->m_rowCategories = categories;
    emit mappingChanged();
}

const QStringList &QItemModelBarDataMapping::rowCategories() const
{
    return d_ptr->m_rowCategories;
}

void QItemModelBarDataMapping::setColumnCategories(const QStringList &categories)
{
    d_ptr->m_columnCategories = categories;
    emit mappingChanged();
}

const QStringList &QItemModelBarDataMapping::columnCategories() const
{
    return d_ptr->m_columnCategories;
}

void QItemModelBarDataMapping::remap(const QString &rowRole,
                                     const QString &columnRole,
                                     const QString &valueRole,
                                     const QStringList &rowCategories,
                                     const QStringList &columnCategories)
{
    d_ptr->m_rowRole = rowRole;
    d_ptr->m_columnRole = columnRole;
    d_ptr->m_valueRole = valueRole;
    d_ptr->m_rowCategories = rowCategories;
    d_ptr->m_columnCategories = columnCategories;

    emit mappingChanged();
}

// QItemModelBarDataMappingPrivate

QItemModelBarDataMappingPrivate::QItemModelBarDataMappingPrivate(QItemModelBarDataMapping *q)
    : QObject(0),
      q_ptr(q)
{
}

QItemModelBarDataMappingPrivate::~QItemModelBarDataMappingPrivate()
{
}

QT_DATAVIS3D_END_NAMESPACE
