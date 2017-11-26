/*
 * DataRowProvider.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: batuhan
 */

#include "DataRowProvider.h"

DataRowProvider::DataRowProvider() {
	// TODO Auto-generated constructor stub

}

DataRowProvider::~DataRowProvider() {
	// TODO Auto-generated destructor stub
}

DataRow* DataRowProvider::processTextRowData(string rowDataAsText, DatasetTemplate &datasetTemplate) {

	DataRow *dataRow = new DataRow();

	string word;
	istringstream stringStream(rowDataAsText);

	int dimension = datasetTemplate.getDimension();
	list<int> columnIndexes = datasetTemplate.getColumnIndexes();

	int currentWordIndex = 0;
	while (stringStream >> word) {

		bool includesIndex = (find(columnIndexes.begin(), columnIndexes.end(), currentWordIndex) != columnIndexes.end());

		if(includesIndex && currentWordIndex < dimension) {

			float dataItem = strtof(word.c_str(), 0);
			(*dataRow).add(dataItem);
		}

		if(currentWordIndex == dimension) {
			int labelValue = atoi(word.c_str());
			(*dataRow).setLabelValue(labelValue);
		}

		currentWordIndex++;
	}

	return dataRow;
}
