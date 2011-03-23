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
#include "pluginLWPR.h"
#include "interfaceLWPRRegress.h"
#include "interfaceLWPRDynamic.h"

using namespace std;

PluginLinear::PluginLinear()
{
	regressors.push_back(new RegrLWPR());
	dynamicals.push_back(new DynamicLWPR());
}

PluginLinear::~PluginLinear()
{
	FOR(i, classifiers.size()) if(classifiers[i]) delete classifiers[i];
	FOR(i, clusterers.size()) if(clusterers[i]) delete clusterers[i];
	FOR(i, regressors.size()) if(regressors[i]) delete regressors[i];
	FOR(i, dynamicals.size()) if(dynamicals[i]) delete dynamicals[i];
	classifiers.clear();
	clusterers.clear();
	regressors.clear();
	dynamicals.clear();
}

#ifndef PLUGIN_CLUSTER
#ifndef PLUGIN_CLASSIFY
Q_EXPORT_PLUGIN2(mld_LWPR, PluginLinear)
#endif
#endif
