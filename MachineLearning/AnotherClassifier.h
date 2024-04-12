#pragma once

#include "Classifier.h"


/// @classes
/// @brief another classifier, inherit Classifier, not implemented yet
class AnotherClassifier : public Classifier
{
	/// @brief function to train KNN classifier
	/// @author Zongping
	/// @date 2024/4/12
	void train(const vector<DataItem>& dataSet);

	/// @brief function to test the classifier's performance
	/// @param testSet 
	/// @return correct predict / size of test size
	/// @author Zongping
	/// @date 2024/4/12
	double test(const vector<DataItem>& testSet);

	/// @brief function to predict by input data
	/// @author Zongping
	/// @date 2024/4/12
	Label predict(const DataItem& d);
};

