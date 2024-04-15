#pragma once


/// @file 
/// @brief this file is class of AnotherClassifier
/// @author Pen
/// @date 2024/4/12
#include "Classifier.h"


/// @classes
/// @brief Another classifier, inherit Classifier, not implemented yet @see Classifier
/// @author Pen
/// @date 2024/4/12
class AnotherClassifier : public Classifier
{
	vector<DataItem> dataSet;

public:
	/// @brief function to train KNN classifier
	/// 
	/// Not implemented yet
	void train(const vector<DataItem>& dataSet);

	/// @brief function to predict by input data
	/// 
	/// Not implemented yet
	Label predict(const DataItem& dataItem);
};

