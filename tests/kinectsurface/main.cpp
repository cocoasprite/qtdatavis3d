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

#include "surfacedata.h"

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QSlider>
#include <QTextEdit>
#include <QScreen>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();

    Q3DSurface *surface = new Q3DSurface();
    Q3DScatter *scatter = new Q3DScatter();
    Q3DBars *bars = new Q3DBars();

    QSize screenSize = surface->screen()->size();

    QWidget *containerSurface = QWidget::createWindowContainer(surface);
    containerSurface->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 2));
    containerSurface->setMaximumSize(screenSize);
    containerSurface->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    containerSurface->setFocusPolicy(Qt::StrongFocus);

    QWidget *containerScatter = QWidget::createWindowContainer(scatter);
    containerScatter->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 2));
    containerScatter->setMaximumSize(screenSize);
    containerScatter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    containerScatter->setFocusPolicy(Qt::StrongFocus);
    containerScatter->setVisible(false);

    QWidget *containerBars = QWidget::createWindowContainer(bars);
    containerBars->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 2));
    containerBars->setMaximumSize(screenSize);
    containerBars->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    containerBars->setFocusPolicy(Qt::StrongFocus);
    containerBars->setVisible(false);

    widget->setWindowTitle(QStringLiteral("Visualization from Kinect depth data"));

    hLayout->addWidget(containerSurface, 1);
    hLayout->addWidget(containerScatter, 1);
    hLayout->addWidget(containerBars, 1);
    hLayout->addLayout(vLayout);

    QPushButton *startButton = new QPushButton(widget);
    startButton->setText(QStringLiteral("Start Kinect"));

    QPushButton *stopButton = new QPushButton(widget);
    stopButton->setText(QStringLiteral("Stop Kinect"));

    QComboBox *resolutionBox = new QComboBox(widget);
    resolutionBox->addItem(QStringLiteral("Low"));
    resolutionBox->addItem(QStringLiteral("Medium"));
    resolutionBox->addItem(QStringLiteral("High"));
    resolutionBox->addItem(QStringLiteral("Max")); // Comment this out if demo machine is low-perf
    resolutionBox->setCurrentIndex(0);

    QComboBox *modeBox = new QComboBox(widget);
    modeBox->addItem(QStringLiteral("Surface Plot"));
    modeBox->addItem(QStringLiteral("Scatter Chart"));
    modeBox->addItem(QStringLiteral("Bar Chart"));
    modeBox->setCurrentIndex(0);

    QSlider *distanceSlider = new QSlider(Qt::Horizontal, widget);
    distanceSlider->setTickInterval(10);
    distanceSlider->setTickPosition(QSlider::TicksBelow);
    distanceSlider->setMinimum(10);
    distanceSlider->setValue(50);
    distanceSlider->setMaximum(200);

    QLinearGradient gradientOne(0, 0, 200, 1);
    gradientOne.setColorAt(0.0, Qt::black);
    gradientOne.setColorAt(0.33, Qt::blue);
    gradientOne.setColorAt(0.67, Qt::red);
    gradientOne.setColorAt(1.0, Qt::yellow);

    QPixmap pm(200, 24);
    QPainter pmp(&pm);
    pmp.setBrush(QBrush(gradientOne));
    pmp.setPen(Qt::NoPen);
    pmp.drawRect(0, 0, 200, 24);

    QPushButton *gradientOneButton = new QPushButton(widget);
    gradientOneButton->setIcon(QIcon(pm));
    gradientOneButton->setIconSize(QSize(200, 24));
    gradientOneButton->setToolTip(QStringLiteral("Colors: Thermal Imitation"));

    QLinearGradient gradientTwo(0, 0, 200, 1);
    gradientTwo.setColorAt(0.0, Qt::white);
    gradientTwo.setColorAt(0.8, Qt::red);
    gradientTwo.setColorAt(1.0, Qt::green);

    pmp.setBrush(QBrush(gradientTwo));
    pmp.setPen(Qt::NoPen);
    pmp.drawRect(0, 0, 200, 24);

    QPushButton *gradientTwoButton = new QPushButton(widget);
    gradientTwoButton->setIcon(QIcon(pm));
    gradientTwoButton->setIconSize(QSize(200, 24));
    gradientTwoButton->setToolTip(QStringLiteral("Colors: Highlight Foreground"));

    QTextEdit *status = new QTextEdit(QStringLiteral("<b>Ready</b><br>"), widget);
    status->setReadOnly(true);

    vLayout->addWidget(startButton);
    vLayout->addWidget(stopButton);
    vLayout->addWidget(new QLabel(QStringLiteral("Change resolution")));
    vLayout->addWidget(resolutionBox);
    vLayout->addWidget(new QLabel(QStringLiteral("Change visualization type")));
    vLayout->addWidget(modeBox);
    vLayout->addWidget(new QLabel(QStringLiteral("Adjust far distance")));
    vLayout->addWidget(distanceSlider);
    vLayout->addWidget(new QLabel(QStringLiteral("Change color scheme")));
    vLayout->addWidget(gradientOneButton);
    vLayout->addWidget(gradientTwoButton);
    vLayout->addWidget(status, 1, Qt::AlignBottom);

    widget->show();

    SurfaceData *datagen = new SurfaceData(surface, scatter, bars, status);
    ContainerChanger changer(containerSurface, containerScatter, containerBars,
                             gradientOneButton, gradientTwoButton);

    QObject::connect(startButton, &QPushButton::clicked, datagen, &SurfaceData::start);
    QObject::connect(stopButton, &QPushButton::clicked, datagen, &SurfaceData::stop);
    QObject::connect(distanceSlider, &QSlider::valueChanged, datagen, &SurfaceData::setDistance);
    QObject::connect(resolutionBox, SIGNAL(activated(int)), datagen, SLOT(setResolution(int)));
    QObject::connect(modeBox, SIGNAL(activated(int)), &changer, SLOT(changeContainer(int)));
    QObject::connect(modeBox, SIGNAL(activated(int)), datagen, SLOT(changeMode(int)));
    QObject::connect(status, &QTextEdit::textChanged, datagen, &SurfaceData::scrollDown);
    QObject::connect(gradientOneButton, &QPushButton::clicked, datagen,
                     &SurfaceData::useGradientOne);
    QObject::connect(gradientTwoButton, &QPushButton::clicked, datagen,
                     &SurfaceData::useGradientTwo);

    datagen->setDistance(distanceSlider->value());

    return app.exec();
}
