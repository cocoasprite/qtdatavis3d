/****************************************************************************
**
** Copyright (C) 2014 Digia Plc
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

import QtQuick 2.1

Item {
    property alias barData: barDataModel
    property alias scatterData: scatterDataModel
    property alias surfaceData: surfaceDataModel

    ListModel {
        id: barDataModel
        ListElement{ year: "2012"; city: "Oulu";     expenses: "4200"; income: "8300"; }
        ListElement{ year: "2012"; city: "Kemi";     expenses: "2100"; income: "6500"; }
        ListElement{ year: "2012"; city: "Helsinki"; expenses: "7040"; income: "7500"; }
        ListElement{ year: "2012"; city: "Tampere";  expenses: "4330"; income: "5800"; }
        ListElement{ year: "2013"; city: "Oulu";     expenses: "3960"; income: "9000"; }
        ListElement{ year: "2013"; city: "Kemi";     expenses: "1990"; income: "3000"; }
        ListElement{ year: "2013"; city: "Helsinki"; expenses: "7230"; income: "9900"; }
        ListElement{ year: "2013"; city: "Tampere";  expenses: "4650"; income: "7600"; }
    }

    ListModel {
        id: scatterDataModel
        ListElement{ xPos: "2.754"; yPos: "1.000"; zPos: "3.362"; }
        ListElement{ xPos: "3.164"; yPos: "2.022"; zPos: "4.348"; }
        ListElement{ xPos: "4.564"; yPos: "1.865"; zPos: "1.000"; }
        ListElement{ xPos: "1.000"; yPos: "1.224"; zPos: "2.983"; }
        ListElement{ xPos: "2.323"; yPos: "2.502"; zPos: "3.133"; }
        ListElement{ xPos: "3.663"; yPos: "3.186"; zPos: "2.843"; }
        ListElement{ xPos: "4.190"; yPos: "4.875"; zPos: "3.942"; }
        ListElement{ xPos: "3.569"; yPos: "3.685"; zPos: "1.456"; }
        ListElement{ xPos: "5.000"; yPos: "5.000"; zPos: "4.678"; }
        ListElement{ xPos: "4.349"; yPos: "3.850"; zPos: "5.000"; }
    }

    ListModel {
        id: surfaceDataModel
        ListElement{ row: "0"; col: "0"; longitude: "20.0"; latitude: "10.0"; pop_density: "4.75"; }
        ListElement{ row: "1"; col: "0"; longitude: "21.1"; latitude: "10.3"; pop_density: "3.00"; }
        ListElement{ row: "2"; col: "0"; longitude: "22.5"; latitude: "10.7"; pop_density: "1.24"; }
        ListElement{ row: "3"; col: "0"; longitude: "24.0"; latitude: "10.5"; pop_density: "2.53"; }
        ListElement{ row: "0"; col: "1"; longitude: "20.2"; latitude: "11.2"; pop_density: "3.55"; }
        ListElement{ row: "1"; col: "1"; longitude: "21.3"; latitude: "11.5"; pop_density: "3.03"; }
        ListElement{ row: "2"; col: "1"; longitude: "22.6"; latitude: "11.7"; pop_density: "3.46"; }
        ListElement{ row: "3"; col: "1"; longitude: "23.4"; latitude: "11.5"; pop_density: "4.12"; }
        ListElement{ row: "0"; col: "2"; longitude: "20.2"; latitude: "12.3"; pop_density: "3.37"; }
        ListElement{ row: "1"; col: "2"; longitude: "21.1"; latitude: "12.4"; pop_density: "2.98"; }
        ListElement{ row: "2"; col: "2"; longitude: "22.5"; latitude: "12.1"; pop_density: "3.33"; }
        ListElement{ row: "3"; col: "2"; longitude: "23.3"; latitude: "12.7"; pop_density: "3.23"; }
        ListElement{ row: "0"; col: "3"; longitude: "20.7"; latitude: "13.3"; pop_density: "5.34"; }
        ListElement{ row: "1"; col: "3"; longitude: "21.5"; latitude: "13.2"; pop_density: "4.54"; }
        ListElement{ row: "2"; col: "3"; longitude: "22.4"; latitude: "13.6"; pop_density: "4.65"; }
        ListElement{ row: "3"; col: "3"; longitude: "23.2"; latitude: "13.4"; pop_density: "6.67"; }
        ListElement{ row: "0"; col: "4"; longitude: "20.6"; latitude: "15.0"; pop_density: "6.01"; }
        ListElement{ row: "1"; col: "4"; longitude: "21.3"; latitude: "14.6"; pop_density: "5.83"; }
        ListElement{ row: "2"; col: "4"; longitude: "22.5"; latitude: "14.8"; pop_density: "5.90"; }
        ListElement{ row: "3"; col: "4"; longitude: "23.7"; latitude: "14.3"; pop_density: "7.32"; }
    }
}
