#pragma once

#include"DataItem.h"

#include <vector>

using namespace std;

/// @classes
/// @brief abstract class of classifier
class Classifier
{

	vector<DataItem> dataSet;

public:
	

	/// @brief A virtual function to train classifier
	/// @author Zongping
	/// @date 2024/4/12
	virtual void train(const vector<DataItem>& dataSet) = 0;

	/// @brief A virtual function to test the classifier's performance
	/// @param testSet 
	/// @return correct predict / size of test size
	/// @author Zongping
	/// @date 2024/4/12
	virtual double test(const vector<DataItem>& testSet) = 0;

	/// @brief A virtual function to predict by input data
	/// @author Zongping
	/// @date 2024/4/12
	virtual Label predict(const DataItem& d) = 0;
};

