/****************************************************************************
**
** Copyright (C) 2014 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.io
**
** This file is part of the Qt Data Visualization module.
**
** Licensees holding valid commercial license for Qt may use this file in
** accordance with the Qt License Agreement provided with the Software
** or, alternatively, in accordance with the terms contained in a written
** agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.io
**
****************************************************************************/

#include "datagenerator.h"
#include <QDebug>

using namespace QtDataVisualization;

Q_DECLARE_METATYPE(QScatter3DSeries *)

DataGenerator::DataGenerator(QObject *parent) :
    QObject(parent)
{
    qRegisterMetaType<QScatter3DSeries *>();
}

DataGenerator::~DataGenerator()
{
    qDebug() << __FUNCTION__;
}

void DataGenerator::generateData(QScatter3DSeries *series, uint count)
{
    QScatterDataArray *dataArray = new QScatterDataArray;
    dataArray->resize(count);
    QScatterDataItem *ptrToDataArray = &dataArray->first();

    float rand_max = float(RAND_MAX);
    for (uint i = 0; i < count; i++) {
            ptrToDataArray->setPosition(QVector3D(float(qrand()) / rand_max,
                                                  float(qrand()) / rand_max,
                                                  float(qrand()) / rand_max));
            ptrToDataArray++;
    }

    series->dataProxy()->resetArray(dataArray);
}

void DataGenerator::add(QScatter3DSeries *series, uint count)
{
    QScatterDataArray appendArray;
    appendArray.resize(count);

    float rand_max = float(RAND_MAX);
    for (uint i = 0; i < count; i++) {
            appendArray[i].setPosition(QVector3D(float(qrand()) / rand_max,
                                                 float(qrand()) / rand_max,
                                                 float(qrand()) / rand_max));
    }

    series->dataProxy()->addItems(appendArray);
}