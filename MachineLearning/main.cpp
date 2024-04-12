
#include "FileIO.h"
#include "NNClassifier.h"
#include "KNNClassifier.h"
#include "AnotherClassifier.h"
#include "DataItem.h"

#include "menu.h"

#include <iostream>

using namespace std;


int main(void) {

	cout <<
		"*********************" << endl <<
		"* welcome to ML lab *";

	FileIO f;
	vector<DataItem> dataSet;
	dataSet = f.readFile("trainingData.txt");


	/* train */
	NNClassifier n;
	

	KNNClassifier kn;


	/* interact */
	int option = -1;
	int k = 0;
	do {
		cout << endl<<
			"*********************" << endl <<
			"Choose Classifier" << endl <<
			"1. NNClassifier (Nearest Neighbour)" << endl <<
			"2. KNNClassifier" << endl <<
			"3. AnotherClassifier" << endl <<
			"0. quit" << endl;
		cin >> option;
		switch (option) {
		case 1:

			n.train(dataSet);
			subMenu(n);

			break;
		case 2: {

			cout << "Please enter k as integer for KNN" << endl;
			cin >> k;
			kn.setK(k);
			kn.train(dataSet);
			subMenu(kn);
			break;
		}
		case 3: {
			cout << "Please enter k as integer for KNN" << endl;
			break;
		}
		case 0: {
			exit(0);
			break;
		}
		default:
			cout << "Invalid Choice" << endl;
			break;
		}

	} while (option);

	

	//NNClassifier n;


	//n.train(dataSet);

	//cout << "NN predict: " << n.predict(DataItem({0,1,0}, UNKNOWN)) << endl;


	/*KNNClassifier kn;
	kn.train(dataSet);
	kn.setK(6);
	cout << "KNN predict: " << kn.predict(DataItem({ 0,1,0 }, UNKNOWN)) << endl;
	cout << "KNN predict: " << kn.predict(DataItem({ 0,0.7,0 }, UNKNOWN)) << endl;
	*/
	//cout << "idk";

	return 0;
}