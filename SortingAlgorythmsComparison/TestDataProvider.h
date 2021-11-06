#pragma once
#include <iostream>
#include <fstream>

class TestDataProvider
{
private:
	std::ofstream saveFile;
	std::ifstream loadFile;

public:
	bool TrySave(std::string toFile, int* values, int valuesCount);
	int TryLoad(std::string fromFile, int** values);
};

