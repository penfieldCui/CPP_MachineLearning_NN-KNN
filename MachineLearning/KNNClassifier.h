#pragma once

/// @file 
/// @brief this file is for concrete class KNNClassifier
/// @author Pen
#include "Classifier.h"

/// @classes
/// @brief K nearest neighbor classifier, inherit Classifier, has a data set of DataItem and a integer k, implement train and predict
/// @author Pen
/// @date 2024/4/12
class KNNClassifier : public Classifier
{
	int k;
	vector<DataItem> dataSet;

public:

	/// @brief k setter
	/// @param k, an integer 
	void setK(int k);


	/// @brief function to train KNN classifier
	/// @param dataSet for training the model
	void train(const vector<DataItem>& dataSet);

	/// @brief function to predict by input data
	/// 
	/// find a set of nearest neighbors of input data point and return the label that appear most frequently in the set
	/// @param single DataItem 
	/// @return Label, return UNKNOWN when the dataSet is empty
	Label predict(const DataItem& dataItem);
};
