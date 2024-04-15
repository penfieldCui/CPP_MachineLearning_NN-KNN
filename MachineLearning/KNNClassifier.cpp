#include "KNNClassifier.h"

#include <algorithm>
#include <map>

void KNNClassifier::setK(int k) {
	this->k = k;
}

// function to train KNN classifier
void KNNClassifier::train(const vector<DataItem>& dataSet) {
	this->dataSet = dataSet;
}

// function to predict by input data
Label KNNClassifier::predict(const DataItem& d) {

	double distance;
	vector<pair<double, Label>> neighbors;

	/*  N * logN   use a lot memory */
	for (auto& neighbor : dataSet) {
		distance = d.distanceFrom(neighbor);
		neighbors.push_back(make_pair(distance, neighbor.getLabel()));
	}
	// sort neighbors
	sort(neighbors.begin(), neighbors.end());
	/*  use a lot memory */
	
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


/*  N * k^2  use less memory */
//for (int i = 0; i < k; i ++) {
//	neighbors.push_back(make_pair(d.distanceFrom(dataSet[i]), dataSet[i].getLabel()));
//}


//for (auto& neighbor : dataSet) {
//	distance = d.distanceFrom(neighbor); //distance of current neighbor

//	//insert
//	for (int i = 0; i < k; i++) {
//		if (distance < neighbors[i].first) {

//			/*  find and overwrite largest distance pair  */
//			int index = 0;
//			double maxDistance = neighbors[0].first;
//			for (int j = 0; j < k; j++) {  //search furthest element
//				if (maxDistance < neighbors[j].first) {
//					index = j;
//					maxDistance = neighbors[j].first;
//				}
//			}
//			// overwrite
//			neighbors[index].first = distance;
//			neighbors[index].second = neighbor.getLabel();
//			break;
//		}
//	}
//}
/*  use less memory  */