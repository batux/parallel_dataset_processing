/*
 * Dataset.h
 *
 *  Created on: Nov 19, 2017
 *      Author: batuhan
 */

#ifndef DATASET_H_
#define DATASET_H_

#include "omp.h"
#include "DataRow.h"
#include "DataRowProvider.h"
#include "DatasetTemplate.h"

using namespace std;

class Dataset {

public:
	Dataset();
	Dataset(DatasetTemplate *datasetTemplate, list<string> dataRawRowsInTextFormat, bool datasetInitializationFlag);
	virtual ~Dataset();
	void setDataTemplate(DatasetTemplate *datasetTemplate);
	list<DataRow*> getDataRows();
	void createDataset();
	void printAllDataRows();

private:
	list<DataRow*> dataRows;
	list<string> dataRawRowsInTextFormat;
	DatasetTemplate *datasetTemplate = NULL;
	DataRowProvider *dataRowProvider = NULL;

	void appendDataRow(DataRow *dataRow);
};

#endif /* DATASET_H_ */
