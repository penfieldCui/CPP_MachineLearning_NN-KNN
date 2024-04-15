#include "Classifier.h"


// function to test the classifier's performance
double Classifier::test(const vector<DataItem>& testSet) {

	if (testSet.size() == 0) {
		cout<< "testSet empty" << endl;
		return 0;
	}

	int passCount = 0;
	for (auto& neighbor : testSet) {
		Label l = this->predict(neighbor);
		if (l == neighbor.getLabel())
			passCount++;
	}

	double ret = (double)passCount / testSet.size();
	return ret;
}