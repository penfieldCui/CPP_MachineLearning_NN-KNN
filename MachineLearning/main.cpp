
#include "FileIO.h"
#include "NNClassifier.h"
#include "KNNClassifier.h"

#include <iostream>



using namespace std;


int main(void) {

	FileIO f;
	vector<DataItem> dataSet;
	dataSet = f.readFile("trainingData.txt");

	//NNClassifier n;


	//n.train(dataSet);

	//cout << "NN predict: " << n.predict(DataItem({0,1,0}, UNKNOWN)) << endl;


	KNNClassifier kn;
	kn.train(dataSet);
	kn.setK(6);
	cout << "KNN predict: " << kn.predict(DataItem({ 0,1,0 }, UNKNOWN)) << endl;
	cout << "KNN predict: " << kn.predict(DataItem({ 0,0.7,0 }, UNKNOWN)) << endl;
	
	cout << "idk";

	return 0;
}