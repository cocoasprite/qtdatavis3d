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

#include "qvalue3daxis.h"
#include "qvalue3daxis_p.h"
#include "utils_p.h"

QT_DATAVISUALIZATION_BEGIN_NAMESPACE

/*!
 * \class QValue3DAxis
 * \inmodule QtDataVisualization
 * \brief The QValue3DAxis class is used for manipulating an axis of a graph.
 * \since Qt Data Visualization 1.0
 *
 * QValue3DAxis provides an axis that can be given a range of values and segment and subsegment
 * counts to divide the range into.
 *
 * Labels are drawn between each segment. Grid lines are drawn between each segment and each
 * subsegment. \note If visible, there will always be at least two grid lines and labels indicating
 * the minimum and the maximum values of the range, as there is always at least one segment.
 */

/*!
 * \qmltype ValueAxis3D
 * \inqmlmodule QtDataVisualization
 * \since QtDataVisualization 1.0
 * \ingroup datavisualization_qml
 * \instantiates QValue3DAxis
 * \inherits AbstractAxis3D
 * \brief The ValueAxis3D type is used for manipulating an axis of a graph.
 *
 * This type provides an axis that can be given a range of values and segment and subsegment
 * counts to divide the range into.
 */


/*!
 * \qmlproperty int ValueAxis3D::segmentCount
 *
 * Defines the number of segments on the axis. This indicates how many labels are drawn. The number
 * of grid lines to be drawn is calculated with formula: \c {segments * subsegments + 1}.
 * The preset default is \c 5, and it can not be below \c 1.
 */

/*!
 * \qmlproperty int ValueAxis3D::subSegmentCount
 *
 * Defines the number of subsegments inside each segment on the axis. Grid lines are drawn between
 * each subsegment, in addition to each segment.
 * The preset default is \c 1, and it can not be below \c 1.
 */

/*!
 * \qmlproperty string ValueAxis3D::labelFormat
 *
 * Defines the label format to be used for the labels on this axis. Supported specifiers are:
 * \c {d, i, o, x, X, f, F, e, E, g, G, c}. See QString::sprintf() for additional details.
 */

/*!
 * Constructs QValue3DAxis with the given \a parent.
 */
QValue3DAxis::QValue3DAxis(QObject *parent) :
    QAbstract3DAxis(new QValue3DAxisPrivate(this), parent)
{
}

/*!
 * Destroys QValue3DAxis.
 */
QValue3DAxis::~QValue3DAxis()
{
}


/*!
 * \property QValue3DAxis::segmentCount
 *
 * Defines the number of segments on the axis. This indicates how many labels are drawn. The number
 * of grid lines to be drawn is calculated with formula: \c {segments * subsegments + 1}.
 * The preset default is \c 5, and it can not be below \c 1.
 *
 * \sa setSubSegmentCount()
 */
void QValue3DAxis::setSegmentCount(int count)
{
    if (count <= 0) {
        qWarning() << "Warning: Illegal segment count automatically adjusted to a legal one:"
                   << count << "-> 1";
        count = 1;
    }
    if (dptr()->m_segmentCount != count){
        dptr()->m_segmentCount = count;
        dptr()->emitLabelsChanged();
        emit segmentCountChanged(count);
    }
}

int QValue3DAxis::segmentCount() const
{
    return dptrc()->m_segmentCount;
}

/*!
 * \property QValue3DAxis::subSegmentCount
 *
 * Defines the number of subsegments inside each segment on the axis. Grid lines are drawn between
 * each subsegment, in addition to each segment.
 * The preset default is \c 1, and it can not be below \c 1.
 *
 * \sa setSegmentCount()
 */
void QValue3DAxis::setSubSegmentCount(int count)
{
    if (count <= 0) {
        qWarning() << "Warning: Illegal subsegment count automatically adjusted to a legal one:"
                   << count << "-> 1";
        count = 1;
    }
    if (dptr()->m_subSegmentCount != count) {
        dptr()->m_subSegmentCount = count;
        emit subSegmentCountChanged(count);
    }
}

int QValue3DAxis::subSegmentCount() const
{
    return dptrc()->m_subSegmentCount;
}

/*!
 * \property QValue3DAxis::labelFormat
 *
 * Defines the label format to be used for the labels on this axis. Supported specifiers are:
 * \c {d, i, o, x, X, f, F, e, E, g, G, c}. See QString::sprintf() for additional details.
 *
 * Usage example:
 *
 * \c {axis->setLabelFormat("%.2f mm");}
 */
void QValue3DAxis::setLabelFormat(const QString &format)
{
    if (dptr()->m_labelFormat != format) {
        dptr()->m_labelFormat = format;
        dptr()->emitLabelsChanged();
        emit labelFormatChanged(format);
    }
}

QString QValue3DAxis::labelFormat() const
{
    return dptrc()->m_labelFormat;
}

/*!
 * \internal
 */
QValue3DAxisPrivate *QValue3DAxis::dptr()
{
    return static_cast<QValue3DAxisPrivate *>(d_ptr.data());
}

/*!
 * \internal
 */
const QValue3DAxisPrivate *QValue3DAxis::dptrc() const
{
    return static_cast<const QValue3DAxisPrivate *>(d_ptr.data());
}

QValue3DAxisPrivate::QValue3DAxisPrivate(QValue3DAxis *q)
    : QAbstract3DAxisPrivate(q, QAbstract3DAxis::AxisTypeValue),
      m_segmentCount(5),
      m_subSegmentCount(1),
      m_labelFormat(Utils::defaultLabelFormat()),
      m_labelsDirty(true)
{
}

QValue3DAxisPrivate::~QValue3DAxisPrivate()
{
}

void QValue3DAxisPrivate::setRange(float min, float max)
{
    bool dirty = (min != m_min || max != m_max);

    QAbstract3DAxisPrivate::setRange(min, max);

    if (dirty)
        emitLabelsChanged();
}

void QValue3DAxisPrivate::setMin(float min)
{
    bool dirty = (min != m_min);

    QAbstract3DAxisPrivate::setMin(min);

    if (dirty)
        emitLabelsChanged();
}

void QValue3DAxisPrivate::setMax(float max)
{
    bool dirty = (max != m_max);

    QAbstract3DAxisPrivate::setMax(max);

    if (dirty)
        emitLabelsChanged();
}

void QValue3DAxisPrivate::emitLabelsChanged()
{
    m_labelsDirty = true;
    emit q_ptr->labelsChanged();
}

void QValue3DAxisPrivate::updateLabels()
{
    if (!m_labelsDirty)
        return;

    m_labelsDirty = false;

    QStringList newLabels;
    newLabels.reserve(m_segmentCount + 1);

    // First label is at axis min, which is an extra segment
    float segmentStep = (m_max - m_min) / m_segmentCount;

    QString formatString(m_labelFormat);
    Utils::ParamType paramType = Utils::findFormatParamType(formatString);
    QByteArray formatArray = formatString.toUtf8();

    for (int i = 0; i < m_segmentCount; i++) {
        float value = m_min + (segmentStep * i);
        newLabels.append(Utils::formatLabel(formatArray, paramType, value));
    }

    // Ensure max label doesn't suffer from any rounding errors
    newLabels.append(Utils::formatLabel(formatArray, paramType, m_max));

    if (m_labels != newLabels)
        m_labels = newLabels;
}

QValue3DAxis *QValue3DAxisPrivate::qptr()
{
    return static_cast<QValue3DAxis *>(q_ptr);
}

QT_DATAVISUALIZATION_END_NAMESPACE