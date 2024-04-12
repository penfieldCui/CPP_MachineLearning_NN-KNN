#include "menu.h"

#include "DataItem.h"
#include <string>
#include <sstream>

using namespace std;


// display sub menu and prompt user to enter data 
void subMenu(Classifier& c) {
	int option;
	FileIO fileIO;

	cout << "1. Use sample data (x,y,z)" << endl <<
		"2. Use file ('trainingData.txt'," <<
		"'testingData.txt', or 'unknownData.txt')" << endl << 
		"0. Go back" << endl;

	while(cin >> option) {
		switch (option) {
		case 1: {

			string line;
			cout << "please enter (x,y,z) , use ',' as delimiter" << endl;
			cin >> line;
			istringstream lineAsStream(line);
			DataItem d(fileIO.readFeaturesFromSStream(lineAsStream), UNKNOWN);

			Label l = c.predict(d);
			cout << " -- Predict result: " << l << endl;
			//cout << "Predict result: " << c.predict(d) << endl;
			return;
		}
		case 2: {
			string fileName;
			cout << "please Enter File Name: ";
			cin >> fileName; // more validation 
			
			vector<DataItem> dataSet = fileIO.readFile(fileName); // 0,0,0

			/* predicting */
			for (int i = 0; i < dataSet.size(); i++) {
				cout << "predicting " << dataSet[i] << endl;
				Label l = c.predict(dataSet[i]);
				cout << "result: " << l << endl;
				dataSet[i].setLabel(l);
			}

			/* write to result.txt */
			fileIO.writeResults("result.txt", dataSet);
				
			return;
		}
		case 0: {
			return;
		}
		default:
			cout << "Invalid Choice" << endl;
			break;
		}
	}
}

