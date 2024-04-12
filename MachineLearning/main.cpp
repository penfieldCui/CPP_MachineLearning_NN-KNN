
#include "FileIO.h"
#include "NNClassifier.h"

#include <iostream>



using namespace std;


int main(void) {

	FileIO f;
	vector<DataItem> dataSet;
	dataSet = f.readFile("trainingData.txt");

	NNClassifier n;
	n.train(dataSet);

	cout << "Label: " << n.predict(DataItem({0,1,0}, UNKNOWN)) << endl;

	cout << "idk";

	return 0;
}