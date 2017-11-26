/*
 * DataRow.h
 *
 *  Created on: Nov 19, 2017
 *      Author: batuhan
 */

#ifndef DATAROW_H_
#define DATAROW_H_

#include "list"
#include "sstream"
#include "algorithm"
#include "iomanip"
#include "DatasetTemplate.h"

using namespace std;

class DataRow {

public:
	DataRow();
	int getLabelValue();
	void setLabelValue(int labelValue);
	list<float> getDataItemList();
	void setDataItemList(list<float> dataItems);
	void add(float dataItem);
	string toString();

private:
	int labelValue;
	list<float> dataItems;
};

#endif /* DATAROW_H_ */
