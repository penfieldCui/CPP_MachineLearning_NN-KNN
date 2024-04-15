#pragma once


/// @file 
/// @brief this file is class of DataItem, enum of Label and their operator overload functions
/// @author Pen
/// @date 2024/4/12
#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

/// @enum Label
/// @brief An enumeration of label
/// 
/// the orientation of phone, 0 means UNKNOWN
enum Label
{
	UNKNOWN,
	FACE_UP = 1,  // 0,0,-1
	FACE_DOWN = 2,  // 0,0,1
	PORTRAIT = 3,  // 0,-1,0
	PORTRAIT_UPSIDE_DOWN = 4,  // 0,1,0
	LANDSCAPE_LEFT = 5,  // -1,0,0
	LANDSCAPE_RIGHT = 6  // 1,0,0
};

/// @classes
/// @brief Data class that hold multidimensional features and label
/// @author Pen
/// @date 2024/4/12
class DataItem
{
	vector <double> features;
	Label label;

public:
	/// @brief Para constructor using initializer 
	/// @param features , double vector 
	/// @param label , enum
	DataItem(vector <double> features, Label label);

	/// @brief Calculate Euclidean distance between two data point
	/// @param an other dataItem 
	/// @return Euclidean distance of this data point and the input data point
	double distanceFrom (const DataItem dataItem) const;

	/// @brief getter of label
	/// @return label of current data, 0 means unknown
	Label getLabel() const;

	/// @brief setter of label
	/// @param label 
	void setLabel(Label label);

	/// @brief getter of feature vector
	/// @return a feature vector of the data
	vector <double> getFeatures() const;
};

/// @brief 
/// 
/// a operator overload that used to print the dataItem
/// @param stream ,ostream type
/// @param x ,dataItem, @see DataItem
/// @return ostream for chain functions call
ostream& operator<<(ostream& stream, DataItem& x);


/// @brief 
/// 
/// a operator overload that used to print the Label
/// @param stream ,ostream type
/// @param x ,Label, @see Label
/// @return ostream for chain functions call
ostream& operator<<(ostream& stream, Label& x);



