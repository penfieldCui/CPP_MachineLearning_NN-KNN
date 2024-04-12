#pragma once

#include "DataItem.h"

#include <iostream>


#include <fstream>
#include <sstream>

#include <vector>
#include <string>


using namespace std;

class FileIO {

public:

	vector<DataItem> readFile(string fileName);

	//void fileHasResults(string fileName);

	//void fileHasNoResults(string fileName);

	void writeResults();

};