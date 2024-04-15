
#include "FileIO.h"
#include "NNClassifier.h"
#include "KNNClassifier.h"
#include "AnotherClassifier.h"
#include "DataItem.h"

#include "subMenu.h"

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

	//AnotherClassifier a;


	/* interact */
	char option = '\0';
	int k = 0;

	// main menu
	do {
		cout << endl<<
			"*********************" << endl <<
			"*        MAIN       *" << endl <<
			"*********************" << endl <<
			"Choose Classifier or exit" << endl <<
			"1. NNClassifier (Nearest Neighbour)" << endl <<
			"2. KNNClassifier" << endl <<
			"3. AnotherClassifier" << endl <<
			"0. quit" << endl;
		cout << "please enter the number: ";
		cin >> option;
		switch (option) {
		case '1':

			cout << endl <<
				"*********************" << endl <<
				"*   NN Classifier   *" << endl;

			n.train(dataSet);
			subMenu(n);

			break;
		case '2': {

			cout << "Please enter k as integer for KNN: ";
			cin >> k;
			if (!(k>0)) {
				cout << "Invalid input" << endl;
				break;
			}

			kn.setK(k);
			kn.train(dataSet);


			cout << endl <<
				"*********************" << endl <<
				"*        KNN        *" << endl;
			subMenu(kn);
			break;
		}
		case '3': {
			cout << endl << "   AnotherClassifier is not implemented yet" << endl;
			break;
		}
		case '0': {
			exit(0);
			break;
		}
		default:
			cout << "Invalid Choice" << endl;
			break;
		}

	} while (option);

	return 0;
}