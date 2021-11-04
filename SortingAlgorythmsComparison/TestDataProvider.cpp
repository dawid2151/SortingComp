#include <iostream>
#include <fstream>
#include "TestDataProvider.h"

bool TestDataProvider::TrySave(std::string toFile, int* values)
{
	int count = sizeof(&values);
	saveFile.open(toFile);
	if (!saveFile.good())
	{
		std::cout << "Could not open '" << toFile << "'" << std::endl;
		return false;
	}
	std::cout << "Size : " << count << std::endl;

}

bool TestDataProvider::TryLoad(std::string fromFile, int* values)
{
	loadFile.open(fromFile);
	if (!loadFile.good())
	{
		std::cout << "Could not open '" << fromFile << "'" << std::endl;
		return false;
	}
	unsigned long long i = 0;
	unsigned long long n = 0;
	loadFile >> n;
	values = new int[n];
	while (!loadFile.eof())
	{
		loadFile >> values[i];
		i++;
	}
	return true;
}