/// Main program
/// Implemetation by Dawid Żyrek

#include <iostream>
#include "SortingAlgorythm.h"
#include "TestValuesGenerator.h"
#include "Stopwatch.h"
#include "QuickSort.cpp"
#include "TestDataProvider.h"

using namespace std;

const int VALUES_COUNT = 10;

void PrintTable(int* table, int numberOfElements)
{
    cout << "Generated table:" << endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << table[i] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    Stopwatch stopwatch;
    TestValuesGenerator generator;
    TestDataProvider dataProvider;
    SortingAlgorythm *algorythm;
    int* tab;

    //Get test values
    generator.SetMaxValue(10);
    tab = generator.GenerateRandomValues(VALUES_COUNT);
    PrintTable(tab, VALUES_COUNT);
    dataProvider.TrySave("temp.txt", tab);

    //select sorting algorythm
    QuickSort quick;
    algorythm = &quick;

    //start measuring
    stopwatch.Start();

    bool completed = algorythm->Sort(tab);
    
    //stop measuring
    stopwatch.Stop();
    cout << "duration : " << stopwatch.Duration()<<"ms" << endl;
}
