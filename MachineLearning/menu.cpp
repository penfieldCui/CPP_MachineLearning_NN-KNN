#include "subMenu.h"


using namespace std;


// display sub menu and prompt user to enter data 
void subMenu(Classifier& c) {
	char option = '\0';
	FileIO fileIO;


	do {

		cout <<
			"*********************" << endl <<
			"1. Predict sample data (x,y,z)" << endl <<
			"2. Predict data in file" << endl <<
			"3. Test with test data file" << endl <<
			"0. Go back" << endl;
		cout << "please enter your choice: ";
		cin >> option;
		switch (option) {
		case '1': {

			string line;
			cout << "please enter (x,y,z) , use ',' as delimiter" << endl;
			cin >> line;
			istringstream lineAsStream(line);
			DataItem d(fileIO.readFeaturesFromSStream(lineAsStream), UNKNOWN);

			Label l = c.predict(d);
			cout << endl<<" - Predict result: " << l << endl << endl;
			break;
		}
		case '2': {
			string fileName;
			cout << "please Enter File Name('unknownData.txt'): ";
			cin >> fileName; // more validation 
			
			vector<DataItem> dataSet = fileIO.readFile(fileName); // 0,0,0

			/* predicting */
			for (int i = 0; i < dataSet.size(); i++) {
				cout << "predicting " << dataSet[i];
				Label l = c.predict(dataSet[i]);
				cout << "   result: " << l << endl;
				dataSet[i].setLabel(l);
			}

			/* write to result.txt */
			fileIO.writeResults("result.txt", dataSet);
			cout << endl << endl << " - Predict result written, plz check result.txt" << endl << endl;
			break;
		}
		case '3': {
			string fileName;
			cout << "please Enter File Name('testingData.txt'): ";
			cin >> fileName; // more validation 
			vector<DataItem> dataSet = fileIO.readFile(fileName); // 0,0,0,0
			double passPercent = 100 * c.test(dataSet);

			cout << endl << " - " << fixed << setprecision(2) << passPercent << "% of test cases passed" << endl << endl;

			break;
		}
		case '0': {
			return;
		}
		default:
			cout << "Invalid Choice: " << option << endl;
			break;
		}

	} while (option);
}

