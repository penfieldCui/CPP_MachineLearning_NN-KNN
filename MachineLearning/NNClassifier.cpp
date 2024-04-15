#include "NNClassifier.h"

// function to train NN classifier
void NNClassifier::train(const vector<DataItem>& dataSet) {
	this->dataSet = dataSet;
}

// function to predict by input data
Label NNClassifier::predict(const DataItem& d) {
	Label nearestLabel = UNKNOWN;
	double distance;
	double min = d.distanceFrom(dataSet[0]);
	for (auto& neighbor: dataSet) {
		distance = d.distanceFrom(neighbor);
		if (distance < min) {
			min = distance;
			nearestLabel = neighbor.getLabel();
		}
	}

	return nearestLabel;
}

