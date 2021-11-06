#include "TestValuesGenerator.h"

TestValuesGenerator::TestValuesGenerator()
{
	srand((unsigned int)time(NULL));
}
void TestValuesGenerator::SetMinValue(int value)
{
	minValue = value;
}
void TestValuesGenerator::SetMaxValue(int value)
{
	maxValue = value;
}

int* TestValuesGenerator::GenerateRandomValues(int numberOfValues) 
{
	int *values = new int[numberOfValues];
	for (int i = 0; i < numberOfValues; i++)
	{
		values[i] = (rand() % (maxValue - minValue + 1)) + minValue;
	}

	return values;
}
/*
min = 2;
max = 10;

 rand() % max				--> 0-9
(rand() % max) + min		--> 2-11
(rand() % (max-min+1)) + min  --> 

*/