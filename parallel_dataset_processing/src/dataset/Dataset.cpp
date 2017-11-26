/*
 * Dataset.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: batuhan
 */

#include "Dataset.h"

Dataset::Dataset() {
	// TODO Auto-generated constructor stub
}

Dataset::Dataset(DatasetTemplate *datasetTemplate, list<string> dataRawRowsInTextFormat, bool datasetInitializationFlag) {

	this->datasetTemplate = datasetTemplate;

	this->dataRawRowsInTextFormat = dataRawRowsInTextFormat;

	this->dataRowProvider = new DataRowProvider();

	if(datasetInitializationFlag) {
		createDataset();
	}
}

Dataset::~Dataset() {
	// TODO Auto-generated destructor stub
}

void Dataset::createDataset() {

	#pragma omp parallel
	{
		int rowIndex = 0;
		DataRow *dataRow = NULL;

		#pragma omp single
		{
			for(list<string>::iterator listItem = this->dataRawRowsInTextFormat.begin(); listItem != this->dataRawRowsInTextFormat.end(); listItem++)
			{
				#pragma omp task firstprivate(listItem) shared(rowIndex, dataRow)
				{
					dataRow = (*this->dataRowProvider).processTextRowData((*listItem), (*this->datasetTemplate));
					cout << "Thread Id: " <<  omp_get_thread_num() << " Data Row Index: " << rowIndex << endl;
					rowIndex++;
				}
				#pragma omp taskwait

				#pragma omp task shared(rowIndex, dataRow)
				{
					appendDataRow(dataRow);
				}
			}
		}
	}
}

void Dataset::appendDataRow(DataRow *dataRow) {
	this->dataRows.push_back(dataRow);
}

void Dataset::printAllDataRows() {

	#pragma omp parallel
	{
		int counter = 0;

		#pragma omp single
		{
			for(list<DataRow*>::iterator dataRow = this->dataRows.begin(); dataRow != this->dataRows.end(); dataRow++)
			{
				#pragma omp task firstprivate(dataRow) shared(counter)
				{
					string dataItemAsText = (*dataRow)->toString();

					cout << "Thread Id: " << omp_get_thread_num() << " Data Id: " << counter << "[ " << dataItemAsText << " ]" << endl;
					counter++;
				}
				#pragma omp taskwait
			}
		}
	}
}

list<DataRow*> Dataset::getDataRows() {
	return this->dataRows;
}

void Dataset::setDataTemplate(DatasetTemplate *datasetTemplate) {
	this->datasetTemplate = datasetTemplate;
}

