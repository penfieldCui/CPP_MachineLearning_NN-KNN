#include "KNNClassifier.h"

#include <map>

void KNNClassifier::setK(int k) {
	this->k = k;
}


// function to train KNN classifier
void KNNClassifier::train(const vector<DataItem> dataSet) {
	this->dataSet = dataSet;
}

// function to test the classifier's performance
double KNNClassifier::test(const vector<DataItem> testSet) {


	return 0;
}

// function to predict by input data
Label KNNClassifier::predict(const DataItem d) {


	


	double distance;
	vector<pair<double, Label>> neighbors;

	for (int i = 0; i < k; i ++) {
		neighbors.push_back(make_pair(d.distanceFrom(dataSet[i]), dataSet[i].getLabel()));
	}


	for (auto& neighbor : dataSet) {
		distance = d.distanceFrom(neighbor); //distance of current neighbor

		//insert
		for (int i = 0; i < k; i++) {
			if (distance < neighbors[i].first) {
				neighbors[i].first = distance;
				neighbors[i].second = neighbor.getLabel();
				break;
			}
		}
	}


	map<Label, int> countLabel;
	for (int i = 0; i < k; i++) {
		countLabel[neighbors[i].second]++;
	}


	int max = 0;
	Label nearestLabel = UNKNOWN;
	for (const auto& pair : countLabel) {
		if (pair.second > max) {
			max = pair.second;
			nearestLabel = pair.first;
		}
	}


	
	return nearestLabel;
}