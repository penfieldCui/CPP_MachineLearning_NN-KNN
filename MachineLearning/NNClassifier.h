#pragma once

/// @file 
/// @brief this file is for concrete class NNClassifier
/// @author Pen
#include "Classifier.h"


/// @classes
/// @brief Nearest neighbor classifier, inherit Classifier, has a data set of DataItem, implement train and predict
/// @author Pen
/// @date 2024/4/12
class NNClassifier: public Classifier
{
	vector<DataItem> dataSet;

public:
	/// @brief function to train nearest neighbor classifier
	/// @date 2024/4/12
	void train(const vector<DataItem>& dataSet);

	/// @brief function to predict input data
	/// 
	/// find the nearest neighbor of input data point and return the label of that neighbor
	/// @param single dataItem 
	/// @return Label, return UNKNOWN when the dataSet is empty
	Label predict(const DataItem& dataItem);
};

