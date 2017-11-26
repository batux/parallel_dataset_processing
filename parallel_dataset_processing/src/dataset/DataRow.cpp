/*
 * DataRow.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: batuhan
 */

#include "DataRow.h"

DataRow::DataRow() {
	this->labelValue = -1;
}

int DataRow::getLabelValue() {
	return this-> labelValue;
}

void DataRow::setLabelValue(int labelValue) {
	this->labelValue = labelValue;
}

void DataRow::setDataItemList(list<float> dataItems) {
	this->dataItems = dataItems;
}

list<float> DataRow::getDataItemList() {
	return this->dataItems;
}

void DataRow::add(float dataItem) {
	this->dataItems.push_back(dataItem);
}

string DataRow::toString() {

	stringstream stringStream;

	stringStream << "Label: ";
	stringStream << (this->getLabelValue());
	stringStream << " ";

	for(list<float>::iterator dataItem = this->dataItems.begin(); dataItem != this->dataItems.end(); dataItem++) {
		stringStream << (*dataItem);
		stringStream << " ";
	}

	string dataItemAsText = stringStream.str();

	return dataItemAsText;
}
