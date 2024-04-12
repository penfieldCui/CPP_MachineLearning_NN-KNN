#include "DataItem.h"

DataItem::DataItem(vector <double> f, Label i) : features(f), label(i) {

}


Label DataItem::getLabel() const{
	return label;
}

void DataItem::setLabel(Label label) {
	this->label = label;
}


vector <double>  DataItem::getFeatures() const {
	return features;
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


ostream& operator<<(ostream& stream, DataItem& x) {
	stream << "data features: ";
	for (double feature : x.getFeatures())
		stream << feature << ' ';
	return stream;
}

ostream& operator<<(ostream& stream, Label& x) {
	switch (x)
	{
	case UNKNOWN:
		stream << "Unknown";
		break;

	case FACE_UP:
		stream << "Face up";
		break;

	case FACE_DOWN:
		stream << "Face down";
		break;

	case PORTRAIT:
		stream << "Portrait";
		break;

	case PORTRAIT_UPSIDE_DOWN:
		stream << "Portrait upside down";
		break;

	case LANDSCAPE_LEFT:
		stream << "Landscape left";
		break;

	case LANDSCAPE_RIGHT:
		stream << "Landscape right";
		break;

	default:
		stream << "UNKNOWN";
		break;
	}

	return stream;
}