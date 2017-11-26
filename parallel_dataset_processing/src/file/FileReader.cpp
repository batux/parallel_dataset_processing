/*
 * FileReader.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: batuhan
 */

#include "FileReader.h"

FileReader::FileReader(string filePath) {
	readFile(filePath);
}

FileReader::FileReader() {

}

FileReader::~FileReader() {
	documentLines.clear();
}

void FileReader::readFile(string filePath) {

	dataSetFile.open(filePath.c_str());

	if (dataSetFile.is_open()) {

		string line;

		while (getline(dataSetFile, line)) {
			addLine(line);
		}

		dataSetFile.close();
	}
}

void FileReader::addLine(string line) {
	documentLines.push_back(line);
}

list<string> FileReader::getAllLines() {
	return documentLines;
}

void FileReader::printAllLines(list<string> lines) {

	int counter = 0;

	for(list<string>::iterator listItem = lines.begin(); listItem != lines.end(); listItem++)
	{
	    cout << "id: " << counter << "[ " << (*listItem) << " ]" << endl;
	    counter++;
	}
}



