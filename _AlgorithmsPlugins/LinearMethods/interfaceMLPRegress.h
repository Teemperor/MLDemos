/*********************************************************************
MLDemos: A User-Friendly visualization toolkit for machine learning
Copyright (C) 2010  Basilio Noris
Contact: mldemos@b4silio.com

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License,
version 3 as published by the Free Software Foundation.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free
Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*********************************************************************/
#ifndef _INTERFACEMLPREGRESS_H_
#define _INTERFACEMLPREGRESS_H_

#include <vector>
#include <interfaces.h>
#include "regressorMLP.h"
#include "ui_paramsMLPRegress.h"

class RegrMLP : public QObject, public RegressorInterface
{
	Q_OBJECT
	Q_INTERFACES(RegressorInterface)
private:
	QWidget *widget;
	Ui::ParametersMLPRegress *params;
public:
	RegrMLP();
	// virtual functions to manage the algorithm creation
	Regressor *GetRegressor();
	void DrawInfo(Canvas *canvas, Regressor *regressor);
	void Draw(Canvas *canvas, Regressor *regressor);

	// virtual functions to manage the GUI and I/O
	QString GetName(){return QString("MLP");};
	QWidget *GetParameterWidget(){return widget;};
	void SetParams(Regressor *regressor);
	void SaveOptions(QSettings &settings);
	bool LoadOptions(QSettings &settings);
	void SaveParams(std::ofstream &stream);
	bool LoadParams(char *line, float value);
};

#endif // _INTERFACEMLPREGRESS_H_
