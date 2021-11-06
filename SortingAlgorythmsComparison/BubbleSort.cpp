#include "SortingAlgorythm.h"
class BubbleSort : public SortingAlgorythm
{
public:
	bool Sort(int* intArray, int elementsCount)
	{
		for(int j=0; j< elementsCount; j++)
			for (int i = 0; i < elementsCount-1; i++)
			{
				if (intArray[i] > intArray[i + 1])
				{
					int tmp = intArray[i];
					intArray[i] = intArray[i + 1];
					intArray[i + 1] = tmp;
				}
			}
		return true;
	}

};