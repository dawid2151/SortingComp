/// Main program
/// Implemetation by Dawid Żyrek

#include <iostream>
#include <cstring>
#include "SortingAlgorythm.h"
#include "TestValuesGenerator.h"
#include "Stopwatch.h"
#include "QuickSort.cpp"
#include "BubbleSort.cpp"
#include "TestDataProvider.h"

using namespace std;

const int MAX_GENERATED_VALUE = 100;
const int VALUES_COUNT = 1000;
const string TEST_SET_FILE_PATH = "test.set";

void PrintTable(int* table, int numberOfElements)
{
    cout << "Array:" << endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << table[i] << " ";
    }
    cout << endl;
}

void ManageGeneration()
{

}
void ManageStorage()
{

}
void ManageTesting() 
{

}

int main(int argc, char *argv[])
{
    Stopwatch stopwatch;
    TestValuesGenerator generator;
    TestDataProvider dataProvider;
    SortingAlgorythm *algorythm;
    int* testArray;

    //Get test values
    generator.SetMaxValue(MAX_GENERATED_VALUE);
    testArray = generator.GenerateRandomValues(VALUES_COUNT);
    cout << "===Generated :" << endl;
    PrintTable(testArray, VALUES_COUNT);
    dataProvider.TrySave(TEST_SET_FILE_PATH, testArray, VALUES_COUNT);

    //select sorting algorythm
    BubbleSort bubble;
    algorythm = &bubble;

    //start measuring
    stopwatch.Start();

    bool completed = algorythm->Sort(testArray, VALUES_COUNT);
    
    //stop measuring
    stopwatch.Stop();
    cout << "===Sorted :" << endl;
    PrintTable(testArray, VALUES_COUNT);
    cout << "Sorting duration : " << stopwatch.Duration()<<"ms" << endl;

    //loading from file
    int* loadArray;
    int loadedElements = dataProvider.TryLoad(TEST_SET_FILE_PATH, &loadArray);
    cout << "Loaded from file: " << endl;
    PrintTable(loadArray, loadedElements);
}
