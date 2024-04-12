#pragma once
#include "Classifier.h"

/// @classes
/// @brief K nearest neighbor classifier, inherit Classifier
/// 
/// use K nearest neighbor to predict the label 
class KNNClassifier : public Classifier
{
	int k;
	vector<DataItem> dataSet;

public:

	/// @brief k setter
	/// @param k, an integer 
	void setK(int k);


	/// @brief function to train KNN classifier
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
