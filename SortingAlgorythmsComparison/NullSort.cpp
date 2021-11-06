#include <iostream>
#include "SortingAlgorythm.h"

class NullSort : public SortingAlgorythm {
public:
	bool Sort(int* intArray, int elementsCount)
	{
		std::cout << "Brak sortowania!" << std::endl;
		return false;
	}

	NullSort()
	{}
};
