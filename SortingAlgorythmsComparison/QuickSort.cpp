#include "SortingAlgorythm.h"

class QuickSort : public SortingAlgorythm {
public:
	bool Sort(int* intArray, int elementsCount) 
	{
        int lp = 0, rp = elementsCount -1;
        int i, j, piv;
        i = (lp + rp) / 2;
        piv = intArray[i];
        intArray[i] = intArray[rp];
        for (j = i = lp; i < rp; i++)
            if (intArray[i] < piv) 
            {
                int tmp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = tmp;
                j++;
            }
        intArray[rp] = intArray[j];
        intArray[j] = piv;

        if (lp < j - 1) Sort(intArray, elementsCount, lp, j - 1);
        if (j + 1 < rp) Sort(intArray, elementsCount, j + 1, rp);
		return false;
	}

    bool Sort(int* intArray, int elementsCount, int left, int right)
    {
        int lp = left, rp = right;
        int i, j, piv;
        i = (lp + rp) / 2;
        piv = intArray[i];
        intArray[i] = intArray[rp];
        for (j = i = lp; i < rp; i++)
            if (intArray[i] < piv)
            {
                int tmp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = tmp;
                j++;
            }
        intArray[rp] = intArray[j];
        intArray[j] = piv;

        if (lp < j - 1) Sort(intArray, elementsCount, lp, j - 1);
        if (j + 1 < rp) Sort(intArray, elementsCount, j + 1, rp);
        return true;
    }

	QuickSort()
	{}
};
