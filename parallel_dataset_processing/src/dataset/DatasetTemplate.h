/*
 * DatasetTemplate.h
 *
 *  Created on: Nov 19, 2017
 *      Author: batuhan
 */

#ifndef DATASETTEMPLATE_H_
#define DATASETTEMPLATE_H_

#include "iostream"
#include "string"
#include "list"

using namespace std;

class DatasetTemplate {

public:
	DatasetTemplate();
	virtual ~DatasetTemplate();

	void setName(string name);
	string getName();
	void setDimension(int dimension);
	int getDimension();
	void setColumnIndexes(list<int> columnIndexes);
	list<int> getColumnIndexes();
	void addColumnIndex(int columnIndex);

private:
	string name;
	int dimension;
	list<int> columnIndexes;
};

#endif /* DATASETTEMPLATE_H_ */
