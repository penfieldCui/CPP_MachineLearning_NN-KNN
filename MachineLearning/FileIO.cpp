#include "FileIO.h"


vector<double> FileIO::readFeaturesFromSStream(istream& lineAsStream) {
	string value;
	vector<double> features;
	for (int i = 0; i < 3; i++) {
		getline(lineAsStream, value, ',');
		features.push_back(stod(value));
	}

	return features;
}


vector<DataItem> FileIO::readFile(string fileName) {
	vector<DataItem> dataSet;
	string line;
	ifstream fin;

	fin.open(fileName);
	if (fin.is_open()) {
		string value;

		while (getline(fin, line)) {

			istringstream lineAsStream(line); //0,0,0  or  0,0,0,1

			vector<double> features = readFeaturesFromSStream(lineAsStream);

			Label l = UNKNOWN;
			if (getline(lineAsStream, value)) {
				l = (Label)stoi(value);
			}
			dataSet.push_back(DataItem(features, l));
		}

	}
	else {
		cout << "Failed open " << fileName << endl;
	}

	return dataSet;
}


ofstream& operator << (ofstream& fout, DataItem d) {
	vector<double> features = d.getFeatures();
	for (int i = 0; i < features.size(); i++) {
		fout << features[i] << ",";
	}	
	Label l = d.getLabel();
	fout << (int)l << "," << l;
	return fout;
}

void  FileIO::writeResults(string fileName, const vector<DataItem>& dataSet) {
	ofstream fout;
	fout.open(fileName);
	if (fout.is_open()) {
		for (DataItem d: dataSet) {
			fout << d << endl;
		}

	}
}