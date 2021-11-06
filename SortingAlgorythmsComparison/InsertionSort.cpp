#include <iostream>
#include "SortingAlgorythm.h"

class InsertionSort : public SortingAlgorythm {
public:
	bool Sort(int* intArray, int elementsCount)
	{
        int i, j, x;
        for (j = elementsCount - 2; j >= 0; j--) 
        {
            x = intArray[j];
            i = j + 1;
            while ((i < elementsCount) && (x > intArray[i])) 
            {
                intArray[i - 1] = intArray[i];
                i++;
            }
            intArray[i - 1] = x;
        }
		return true;
	}

	InsertionSort()
	{}
};
