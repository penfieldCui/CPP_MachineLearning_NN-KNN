#pragma once

#include "Classifier.h"

using namespace std;


/// @classes
/// @brief nearest neighbor classifier, inherit Classifier
class NNClassifier: public Classifier
{
	vector<DataItem> dataSet;

public:
	/// @brief function to train classifier
	/// @author Zongping
	/// @date 2024/4/12
	void train(const vector<DataItem> dataSet);

	/// @brief function to test the classifier's performance
	/// @param testSet 
	/// @return correct predict / size of test size
	/// @author Zongping
	/// @date 2024/4/12
	double test(const vector<DataItem> testSet);

	/// @brief function to predict by input data
	/// @author Zongping
	/// @date 2024/4/12
	Label predict(const DataItem d);
};

