#pragma once

/// @file 
/// @brief this file is for subMenu
/// @author Campbell
#include <iostream>
#include "FileIO.h"
#include "DataItem.h"
#include "Classifier.h"

#include <string>
#include <sstream>
#include <iomanip>



/// @brief Display sub menu and prompt user to enter data
/// 
/// Include the operation of a classifier that allow user to interact
/// @param classifier reference
void subMenu(Classifier& classifier);