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
#include "interfaceKNNDynamic.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>

using namespace std;

DynamicKNN::DynamicKNN()
{
	params = new Ui::ParametersKNNDynamic();
	params->setupUi(widget = new QWidget());
}

void DynamicKNN::SetParams(Dynamical *dynamical)
{
	if(!dynamical) return;
	int k = params->knnKspin->value();
	int metricType = params->knnNormCombo->currentIndex();
	int metricP = params->knnNormSpin->value();

	((DynamicalKNN *)dynamical)->SetParams(k, metricType, metricP);
}

Dynamical *DynamicKNN::GetDynamical()
{
	DynamicalKNN *dynamical = new DynamicalKNN();
	SetParams(dynamical);
	return dynamical;
}

void DynamicKNN::DrawInfo(Canvas *canvas, Dynamical *dynamical)
{
	if(!canvas || !dynamical) return;
	int w = canvas->width();
	int h = canvas->height();
	QPixmap infoPixmap(w, h);
	QBitmap bitmap(w,h);
	bitmap.clear();
	infoPixmap.setMask(bitmap);
	infoPixmap.fill(Qt::transparent);

	canvas->infoPixmap = infoPixmap;
}

void DynamicKNN::Draw(Canvas *canvas, Dynamical *dynamical)
{
	if(!dynamical || !canvas) return;
	if(!dynamical) return;
	DrawInfo(canvas, dynamical);
	int w = canvas->width();
	int h = canvas->height();
	canvas->modelPixmap = QPixmap(w,h);
	canvas->confidencePixmap = QPixmap(w,h);
	QBitmap bitmap(w,h);
	bitmap.clear();
	canvas->modelPixmap.setMask(bitmap);
	canvas->modelPixmap.fill(Qt::transparent);
	canvas->repaint();
}

void DynamicKNN::SaveOptions(QSettings &settings)
{
	settings.setValue("knnK", params->knnKspin->value());
	settings.setValue("knnNorm", params->knnNormCombo->currentIndex());
	settings.setValue("knnPower", params->knnNormSpin->value());
}

bool DynamicKNN::LoadOptions(QSettings &settings)
{
	if(settings.contains("knnK")) params->knnKspin->setValue(settings.value("knnK").toFloat());
	if(settings.contains("knnNorm")) params->knnNormCombo->setCurrentIndex(settings.value("knnNorm").toInt());
	if(settings.contains("knnPower")) params->knnNormSpin->setValue(settings.value("knnPower").toFloat());
	return true;
}

void DynamicKNN::SaveParams(std::ofstream &file)
{
	file << "dynamicalOptions" << ":" << "knnK" << " " << params->knnKspin->value() << std::endl;
	file << "dynamicalOptions" << ":" << "knnNorm" << " " << params->knnNormCombo->currentIndex() << std::endl;
	file << "dynamicalOptions" << ":" << "knnPower" << " " << params->knnNormSpin->value() << std::endl;
}

bool DynamicKNN::LoadParams(char *line, float value)
{
	if(endsWith(line,"knnK")) params->knnKspin->setValue((int)value);
	if(endsWith(line,"knnNorm")) params->knnNormCombo->setCurrentIndex((int)value);
	if(endsWith(line,"knnPower")) params->knnNormSpin->setValue((int)value);
	return true;
}
