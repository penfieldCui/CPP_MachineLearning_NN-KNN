#include "DataItem.h"


DataItem::DataItem(vector <double> f, Label i) : features(f), label(i) {

}


Label DataItem::getLabel() const{
	return label;
}

// Euclidean distance
double DataItem::distanceFrom(const DataItem d) const {
	int size = features.size(); //dimensional of feature
	double sum = 0;
	for (int i = 0 ; i < size ; i++)
	{
		sum += pow(features[i] - d.features[i], 2);
	}
	return sqrt(sum);
}
