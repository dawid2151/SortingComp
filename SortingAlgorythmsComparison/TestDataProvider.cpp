#include "TestDataProvider.h"

bool TestDataProvider::TrySave(std::string toFile, int* values, int valuesCount)
{
	saveFile.open(toFile);
	if (!saveFile.good())
	{
		std::cout << "Could not open '" << toFile << "'" << std::endl;
		return false;
	}
	saveFile << valuesCount << " ";
	for (int i = 0; i < valuesCount; i++)
	{
		saveFile << values[i] << " ";
	}
	saveFile.close();
	return true;
}

int TestDataProvider::TryLoad(std::string fromFile, int** values)
{
	int i = 0;
	loadFile.open(fromFile);
	if (!loadFile.good())
	{
		std::cout << "Could not open '" << fromFile << "'" << std::endl;
		return false;
	}
	int valuesCount = 0;
	loadFile >> valuesCount;
	*values = new int[valuesCount];
	for (i; i < valuesCount; i++)
	{
		loadFile >> (*values)[i];
	}
	return i;
}