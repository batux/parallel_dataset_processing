/*
 * DataRowProvider.h
 *
 *  Created on: Nov 26, 2017
 *      Author: batuhan
 */

#ifndef DATAROWPROVIDER_H_
#define DATAROWPROVIDER_H_

#include "algorithm"
#include "DataRow.h"
#include "DatasetTemplate.h"

using namespace std;

class DataRowProvider {

public:
	DataRowProvider();
	virtual ~DataRowProvider();
	DataRow* processTextRowData(string rowDataAsText, DatasetTemplate &datasetTemplate);

};

#endif /* DATAROWPROVIDER_H_ */
