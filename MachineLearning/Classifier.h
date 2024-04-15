#pragma once


/// @file 
/// @brief this file is class of AnotherClassifier
/// @author Pen
/// @date 2024/4/12
#include"DataItem.h"
#include <vector>

using namespace std;

/// @classes
/// @brief abstract class of classifier, with a test function that have being implemented in Classifier.cpp
/// @date 2024/4/12
class Classifier
{

public:
	
	/// @brief A virtual function to train classifier
	/// @param dataSet for training the model
	virtual void train(const vector<DataItem>& dataSet) = 0;

	/// @brief A function to test the classifier's performance
	/// @param testSet for testing the module
	/// @return correct predict / size of test data
	double test(const vector<DataItem>& testSet);

	/// @brief A virtual function to predict by input data
	/// @param dataItem 
	/// @return the predicted label
	virtual Label predict(const DataItem& dataItem) = 0;
};

