/*
 * FileReader.h
 *
 *  Created on: Nov 19, 2017
 *      Author: batuhan
 */

#ifndef FILEREADER_H_
#define FILEREADER_H_

#include "iostream"
#include "string"
#include "list"
#include "fstream"

using namespace std;

class FileReader {
public:
	FileReader();
	FileReader(string filePath);
	virtual ~FileReader();
	list<string> getAllLines();
	void printAllLines(list<string> lines);

private:
	ifstream dataSetFile;
	list<string> documentLines;

	void readFile(string filePath);
	void addLine(string line);
};

#endif /* FILEREADER_H_ */
