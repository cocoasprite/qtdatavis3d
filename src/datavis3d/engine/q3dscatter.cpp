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

#include "q3dscatter.h"
#include "q3dscatter_p.h"
#include "scatter3dcontroller_p.h"
#include "qvalueaxis.h"

#include <QMouseEvent>

#include <QDebug>

QT_DATAVIS3D_BEGIN_NAMESPACE

/*!
 * \class Q3DScatter
 * \inmodule QtDataVis3D
 * \brief The Q3DScatter class provides methods for rendering 3D scatter graphs.
 * \since 1.0.0
 *
 * This class enables developers to render bar graphs in 3D and to view them by rotating the scene
 * freely. Rotation is done by holding down the right mouse button and moving the mouse. Zooming
 * is done by mouse wheel. Selection, if enabled, is done by left mouse button. The scene can be
 * reset to default camera view by clicking mouse wheel. In touch devices rotation is done
 * by tap-and-move, selection by tap-and-hold and zoom by pinch.
 *
 * Methods are provided for changing bar types, themes, bar selection modes and so on. See the
 * methods for more detailed descriptions.
 *
 * \section1 How to construct a minimal Q3DScatter chart
 *
 * After constructing Q3DScatter, you need to set up sample space using setupSampleSpace(). Let's
 * set the sample space to 5 rows and 5 columns:
 *
 * \snippet doc_src_q3dscatter_construction.cpp 0
 *
 * Now Q3DScatter is ready to receive data to be rendered. Add one row of 5 floats into the data
 * set:
 *
 * \snippet doc_src_q3dscatter_construction.cpp 1
 *
 * \note We set the sample space to 5 x 5, but we are inserting only one row of data. This is ok,
 * the rest of the rows will just be blank.
 *
 * Finally you will need to set it visible:
 *
 * \snippet doc_src_q3dscatter_construction.cpp 2
 *
 * The complete code needed to create and display this chart is:
 *
 * \snippet doc_src_q3dscatter_construction.cpp 3
 *
 * And this is what those few lines of code produce:
 *
 * \image q3dscatter-minimal.png
 *
 * The scene can be rotated and zoomed into, but no other interaction is included in this minimal
 * code example. You can learn more by familiarizing yourself with the examples provided, like
 * the \l{Rainfall Example} or the \l{Widget Example}.
 *
 * \sa Q3DMaps, {Qt Data Visualization 3D C++ Classes}
 */

/*!
 * Constructs a new 3D scatter window.
 */
Q3DScatter::Q3DScatter()
    : d_ptr(new Q3DScatterPrivate(this, geometry()))
{
    d_ptr->m_shared->initializeOpenGL();
    QObject::connect(d_ptr->m_shared, &Abstract3DController::shadowQualityChanged, this,
                     &Q3DScatter::handleShadowQualityUpdate);
}

/*!
 *  Destroys the 3D scatter window.
 */
Q3DScatter::~Q3DScatter()
{
}

/*!
 * \internal
 */
void Q3DScatter::render()
{
    d_ptr->m_shared->synchDataToRenderer();
    d_ptr->m_shared->render();
}

void Q3DScatter::handleShadowQualityUpdate(QDataVis::ShadowQuality quality)
{
    emit shadowQualityChanged(quality);
}

#if defined(Q_OS_ANDROID)
/*!
 * \internal
 */
void Q3DScatter::mouseDoubleClickEvent(QMouseEvent *event)
{
    d_ptr->m_shared->mouseDoubleClickEvent(event);
}

/*!
 * \internal
 */
void Q3DScatter::touchEvent(QTouchEvent *event)
{
    d_ptr->m_shared->touchEvent(event);
}
#endif

/*!
 * \internal
 */
void Q3DScatter::mousePressEvent(QMouseEvent *event)
{
    d_ptr->m_shared->mousePressEvent(event, event->pos());
}

/*!
 * \internal
 */
void Q3DScatter::mouseReleaseEvent(QMouseEvent *event)
{
    d_ptr->m_shared->mouseReleaseEvent(event, event->pos());
}

/*!
 * \internal
 */
void Q3DScatter::mouseMoveEvent(QMouseEvent *event)
{
    d_ptr->m_shared->mouseMoveEvent(event, event->pos());
}

/*!
 * \internal
 */
void Q3DScatter::wheelEvent(QWheelEvent *event)
{
    d_ptr->m_shared->wheelEvent(event);
}

/*!
 * \internal
 */
void Q3DScatter::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    d_ptr->m_shared->setSize(width(), height());
}

// TODO: Document
// Size
void Q3DScatter::setWidth(const int width)
{
    d_ptr->m_shared->setWidth(width);
    QWindow::setWidth(width);
}

void Q3DScatter::setHeight(const int height)
{
    d_ptr->m_shared->setHeight(height);
    QWindow::setHeight(height);
}

/*!
 * \a style One of the values in \c QDataVis::MeshStyle. \c Spheres by default.
 *
 * \a smooth A flag to set shading to smooth. \c false by default.
 *
 * Sets the object type to one of the supplied ones.
 *
 * \sa setMeshFileName()
 */
void Q3DScatter::setObjectType(QDataVis::MeshStyle style, bool smooth)
{
    d_ptr->m_shared->setObjectType(style, smooth);
}

/*!
 * \a preset Move camera to a predefined position from \c QDataVis::CameraPreset.
 *
 * Moves camera to a predefined position.
 */
void Q3DScatter::setCameraPreset(QDataVis::CameraPreset preset)
{
    d_ptr->m_shared->setCameraPreset(preset);
}

/*!
 * \a horizontal Horizontal angle for camera.
 *
 * \a vertical Vertical angle for camera.
 *
 * \a distance Distance from the center. \c 100 by default.
 *
 * Move camera to a wanted position based on horizontal and veritcal angles. Angles are limited
 * to -180...180 in horizontal direction and -90...90 in vertical.
 * Distance is adjustable between 10 and 500.
 */
void Q3DScatter::setCameraPosition(qreal horizontal, qreal vertical, int distance)
{
    d_ptr->m_shared->setCameraPosition(GLfloat(horizontal), GLfloat(vertical), GLint(distance));
}

/*!
 * \a theme Apply a predefined theme from \c QDataVis::ColorTheme.
 *
 * Sets a predefined theme. Theme affects object colors, label colors, text color, background color,
 * window color and grid color. Lighting is also adjusted by themes.
 */
void Q3DScatter::setTheme(QDataVis::ColorTheme theme)
{
    d_ptr->m_shared->setColorTheme(theme);
}

/*!
 * \a baseColor The base color of an object. If all other colors are black, this sets the final
 * color of the object.
 *
 * \a heightColor This color is added to the object based on its y-position. The higher the object,
 * the more prominent this color becomes. Setting this black keeps the color unchanged regardless
 * of y-position.
 *
 * \a depthColor This color becomes more prominent the further back in z-position the object is.
 * Setting this black keeps objects the same color regardless of "depth" in the set.
 *
 * \a uniform A flag to define if color needs to be uniform throughout object's length, or will the
 * colors be applied by height. \c true by default.
 *
 * Set object color using your own colors. This overrides colors from theme.
 */
void Q3DScatter::setObjectColor(QColor baseColor, QColor heightColor, QColor depthColor, bool uniform)
{
    d_ptr->m_shared->setObjectColor(baseColor, heightColor, depthColor, uniform);
}

/*!
 * \property Q3DScatter::selectionMode
 *
 * \a mode Set object selection mode from \c QDataVis::SelectionMode. \c ModeItem by default.
 *
 * Sets object selection mode to be used.
 */
void Q3DScatter::setSelectionMode(QDataVis::SelectionMode mode)
{
    d_ptr->m_shared->setSelectionMode(mode);
}

QDataVis::SelectionMode Q3DScatter::selectionMode() const
{
    return d_ptr->m_shared->selectionMode();
}

/*!
 * \property Q3DScatter::windowTitle
 *
 * \a title QString label to be used as window title.
 *
 * Sets the window title. The default is application executable name.
 */
void Q3DScatter::setWindowTitle(const QString &title)
{
    setTitle(title);
}

QString Q3DScatter::windowTitle() const
{
    return title();
}

/*!
 * \a objFileName File name of a mesh object. Object needs to be in Wavefront obj format
 * and include vertices, normals and UVs. It also needs to be in triangles.
 *
 * Override object type with an object mesh. \sa setObjectType()
 */
void Q3DScatter::setMeshFileName(const QString &objFileName)
{
    d_ptr->m_shared->setMeshFileName(objFileName);
}

/*!
 * \property Q3DScatter::fontSize
 *
 * \a fontsize Size of the font.
 *
 * Sets font size.
 */
void Q3DScatter::setFontSize(float fontsize)
{
    d_ptr->m_shared->setFontSize(fontsize);
}

float Q3DScatter::fontSize() const
{
    return d_ptr->m_shared->fontSize();
}

/*!
 * \property Q3DScatter::font
 *
 * \a font QFont to be used for labels. \c Arial by default.
 *
 * Sets the font for labels.
 */
void Q3DScatter::setFont(const QFont &font)
{
    d_ptr->m_shared->setFont(font);
}

QFont Q3DScatter::font() const
{
    return d_ptr->m_shared->font();
}

/*!
 * \property Q3DScatter::labelTransparency
 *
 * \a transparency Transparency level of labels from \c QDataVis::LabelTransparency.
 * \c TransparencyFromTheme by default.
 *
 * Sets label transparency.
 */
void Q3DScatter::setLabelTransparency(QDataVis::LabelTransparency transparency)
{
    d_ptr->m_shared->setLabelTransparency(transparency);
}

QDataVis::LabelTransparency Q3DScatter::labelTransparency() const
{
    return d_ptr->m_shared->labelTransparency();
}

/*!
 * \property Q3DScatter::gridVisible
 *
 * \a visible Flag to enable or disable grid. \c true by default.
 *
 * Sets grid drawing on or off.
 */
void Q3DScatter::setGridVisible(bool visible)
{
    d_ptr->m_shared->setGridEnabled(visible);
}

bool Q3DScatter::isGridVisible() const
{
    return d_ptr->m_shared->gridEnabled();
}

/*!
 * \property Q3DScatter::backgroundVisible
 *
 * \a visible Flag to enable or disable background. \c true by default.
 *
 * Sets backround rendering on or off.
 */
void Q3DScatter::setBackgroundVisible(bool visible)
{
    d_ptr->m_shared->setBackgroundEnabled(visible);
}

bool Q3DScatter::isBackgroundVisible() const
{
    return d_ptr->m_shared->backgroundEnabled();
}

/*!
 * \property Q3DScatter::shadowQuality
 *
 * \a quality Shadow quality from \c QDataVis::ShadowQuality. \c ShadowLow by default.
 *
 * Sets shadow quality. If setting QDataVis::ShadowQuality of a certain level fails, a level is lowered
 * until it is successful and shadowQualityChanged signal is emitted for each time the change is done.
 */
void Q3DScatter::setShadowQuality(QDataVis::ShadowQuality quality)
{
    return d_ptr->m_shared->setShadowQuality(quality);
}

QDataVis::ShadowQuality Q3DScatter::shadowQuality() const
{
    return d_ptr->m_shared->shadowQuality();
}

void Q3DScatter::setValueAxisX(QValueAxis *axis)
{
    Q_ASSERT(axis);

    return d_ptr->m_shared->setAxisX(axis);
}

QValueAxis *Q3DScatter::valueAxisX()
{
    return static_cast<QValueAxis *>(d_ptr->m_shared->axisX());
}

void Q3DScatter::setValueAxisY(QValueAxis *axis)
{
    Q_ASSERT(axis);

    return d_ptr->m_shared->setAxisY(axis);
}

QValueAxis *Q3DScatter::valueAxisY()
{
    return static_cast<QValueAxis *>(d_ptr->m_shared->axisY());
}

void Q3DScatter::setValueAxisZ(QValueAxis *axis)
{
    Q_ASSERT(axis);

    return d_ptr->m_shared->setAxisZ(axis);
}

QValueAxis *Q3DScatter::valueAxisZ()
{
    return static_cast<QValueAxis *>(d_ptr->m_shared->axisZ());
}

void Q3DScatter::setDataProxy(QScatterDataProxy *proxy)
{
    d_ptr->m_shared->setDataProxy(proxy);
}

QScatterDataProxy *Q3DScatter::dataProxy()
{
    return d_ptr->m_shared->dataProxy();
}

Q3DScatterPrivate::Q3DScatterPrivate(Q3DScatter *q, QRect rect)
    : q_ptr(q),
      m_shared(new Scatter3DController(rect))
{
}

Q3DScatterPrivate::~Q3DScatterPrivate()
{
    qDebug() << "Destroying Q3DScatterPrivate";
    delete m_shared;
}

QT_DATAVIS3D_END_NAMESPACE