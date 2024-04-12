#include "FileIO.h"



vector<DataItem> FileIO::readFile(string fileName) {
	vector<DataItem> dataSet;
	string line;
	ifstream fin;

	

	fin.open(fileName);
	if (fin.is_open()) {
		string value;

		while (getline(fin, line)) {
			vector<double> features;
			istringstream lineAsStream(line); //0,0,0  or  0,0,0,1
			for (int i = 0; i < 3; i ++) {
				getline(lineAsStream, value, ',');
				features.push_back(stod(value));
			}
			getline(lineAsStream, value);
			Label l = (Label)stoi(value);
			dataSet.push_back(DataItem(features, l));
		}

	}
	else {
		cout << "Failed open " << fileName << endl;
	}

	return dataSet;
}