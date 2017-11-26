//============================================================================
// Name        : parallel_dataset_processing.cpp
// Author      : Batuhan Duzgun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "iostream"
#include "omp.h"
#include "file/FileReader.h"
#include "dataset/Dataset.h"
#include "dataset/DatasetTemplate.h"

using namespace std;

int main() {

	FileReader *fileReader = new FileReader("dataset/Aust.txt");

	list<string> lines = (*fileReader).getAllLines();

	// (*fileReader).printAllLines(lines);

	list<int> columnIndexes;
	columnIndexes.push_back(2);
	columnIndexes.push_back(3);
	columnIndexes.push_back(4);
	columnIndexes.push_back(12);
	columnIndexes.push_back(14);

	DatasetTemplate *datasetTemplate = new DatasetTemplate();
	(*datasetTemplate).setName("aust");
	(*datasetTemplate).setDimension(13);
	(*datasetTemplate).setColumnIndexes(columnIndexes);

	Dataset *trainingDataSet = new Dataset(datasetTemplate, lines, false);
	(*trainingDataSet).createDataset();
	(*trainingDataSet).printAllDataRows();

	return 0;
}
