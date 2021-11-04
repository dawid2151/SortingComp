#pragma once

#include <fstream>

class TestDataProvider
{
private:
	std::ofstream saveFile;
	std::ifstream loadFile;

public:
	bool TrySave(std::string toFile, int* values);
	bool TryLoad(std::string fromFile, int* values);
};

