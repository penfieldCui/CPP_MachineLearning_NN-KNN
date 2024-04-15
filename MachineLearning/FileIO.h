#pragma once

/// @file 
/// @brief this file is class of FileIO
/// @author Tyler
/// @date 2024/4/12

#include "DataItem.h"

#include <iostream>


#include <fstream>
#include <sstream>

#include <vector>
#include <string>


using namespace std;


/// @classes
/// @brief a class to handle file I/O, including read file, write and read value from stream
/// @author Tyler
/// @date 2024/4/12
class FileIO {

public:
	/// @brief 
	/// 
	/// read dataSet from file
	/// @param fileName 
	/// @return data vector
	vector<DataItem> readFile(string fileName);


	/// @brief 
	/// 
	/// read features from a stream
	/// @param istringstream 
	/// @return feature vector
	vector<double> readFeaturesFromSStream(istream& lineAsStream);

	/// @brief 
	/// 
	/// write data result to file
	/// @param fileName 
	/// @param data vector
	void writeResults(string fileName, const vector<DataItem>& dataSet);
};