/*
 * DatasetTemplate.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: batuhan
 */

#include "DatasetTemplate.h"

DatasetTemplate::DatasetTemplate() {
	setName("");
	setDimension(0);
}

DatasetTemplate::~DatasetTemplate() {
	this->columnIndexes.clear();
}

void DatasetTemplate::setName(string name) {
	this->name = name;
}

string DatasetTemplate::getName() {
	return this->name;
}

void DatasetTemplate::setDimension(int dimension) {
	this->dimension = dimension;
}

int DatasetTemplate::getDimension() {
	return this->dimension;
}

void DatasetTemplate::setColumnIndexes(list<int> columnIndexes) {
	this->columnIndexes = columnIndexes;
}

list<int> DatasetTemplate::getColumnIndexes() {
	return this->columnIndexes;
}

void DatasetTemplate::addColumnIndex(int columnIndex) {
	this->columnIndexes.push_back(columnIndex);
}
