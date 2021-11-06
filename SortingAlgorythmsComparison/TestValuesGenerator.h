#pragma once
#include <climits>
#include <ctime>
#include <cstdlib>
class TestValuesGenerator
{
private:
	int minValue = 0;
	int maxValue = INT_MAX;
public:
	int* GenerateRandomValues(int numberOfValues);
	void SetMinValue(int value);
	void SetMaxValue(int value);

	TestValuesGenerator();
};

