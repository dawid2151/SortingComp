/// Main program
/// Implemetation by Dawid Żyrek

#include <iostream>
#include <cstring>
#include <Windows.h>
#include "SortingAlgorythm.h"
#include "TestValuesGenerator.h"
#include "TestDataProvider.h"
#include "Stopwatch.h"
#include "QuickSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "NullSort.cpp"

using namespace std;

int* testArray;
int n;
Stopwatch stopwatch;
TestValuesGenerator generator;
TestDataProvider dataProvider;
SortingAlgorythm* algorythm;


void PrintTable(int* table, int numberOfElements)
{
    cout << "Array:" << endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << table[i] << " ";
    }
    cout << endl;
}

SortingAlgorythm* ChooseAlgorythm()
{
    BubbleSort bubble;
    QuickSort quick;
    InsertionSort insertion;
    NullSort nullsort;
    
    int alg;
    cout << "Wybierz algorytm sortowania :" << endl;
    cout << "   1.Bubble Sort" << endl;
    cout << "   2.Quick Sort" << endl;
    cout << "   3.Insertion Sort" << endl;
    cin >> alg;
    switch (alg)
    {
    case 1:
        return &bubble;
    case 2:
        return &quick;
    case 3:
        return &insertion;
    default:
        return &nullsort;
    }
}
void PrintLegend()
{
    cout << "Komendy:" << endl;
    cout << "  1.Generuj tablicę" << endl;
    cout << "  2.Sortuj tablicę" << endl;
    cout << "  3.Zapisz do pliku" << endl;
    cout << "  4.Ładuj z pliku" << endl;
    cout << "  9.Wyjdź" << endl;
}
void Clear()
{
    system("cls");
}
void Generate()
{
    Clear();
    int min, max;
    cout << endl << "Ile elementów? ";
    cin >> n;
    cout << endl << "Wartości od : ";
    cin >> min;
    cout << endl << "Do : ";
    cin >> max;
    generator.SetMinValue(min);
    generator.SetMaxValue(max);
    testArray = generator.GenerateRandomValues(n);
    cout << "===Generated :" << endl;
    PrintTable(testArray, n);
}
void Sort()
{
    Clear();
    //select sorting algorythm
    algorythm = ChooseAlgorythm();

    //start measuring
    stopwatch.Start();

    bool completed = algorythm->Sort(testArray, n);

    //stop measuring
    stopwatch.Stop();
    cout << "===Sorted :" << endl;
    PrintTable(testArray, n);
    cout << "Sorting duration : " << stopwatch.Duration() << "ms" << endl;
}
void Save()
{
    Clear();
    string filename;
    cout << "Zapisz do pliku o nazwie : ";
    cin >> filename;
    if (dataProvider.TrySave(filename, testArray, n))
        cout << "Zapisano pomyślnie!" << endl;
}
void Load()
{
    Clear();
    string filename;
    cout << "Podaj nazwę pliku : ";
    cin >> filename;
    n = dataProvider.TryLoad(filename, &testArray);
    cout << "Loaded from file. " << endl;
    PrintTable(testArray, n);
}
void Quit()
{
    Clear();
    string answer;
    string fin = "Tak, jestem absolutnie pewien że chcę opuścić ten program.";
    cout << "Czy na pewno chcesz wyjść? ";
    cin >> answer;
    if (answer == "tak")
    {
        Sleep(1500);
        cout << endl << "Wychodząć, opuścisz ten program. Czy jesteś absolutnie pewien że chcesz wyjść z tego programu? ";
        cin >> answer;
        if (answer == "tak")
        {
            Sleep(3000);
            cout << endl << "No cóż ";
            Sleep(3000);
            cout<<"w takim razie... ";
            Sleep(4000);
            cout << endl << "Wpisz : '" + fin + "' aby opuścić program ";
            cin >> answer;
            if(answer == fin)
                exit(0);              
        }
    }
    cout << endl << "Odpowiedź nierozpoznana!" << endl;
}

void MainLoop()
{
    int command;
    PrintLegend();
    cout << "Wybierz komendę: ";
    cin >> command;
    switch (command)
    {
    case 1:
        Generate();
        break;
    case 2:
        Sort();
        break;
    case 3:
        Save();
        break;
    case 4:
        Load();
        break;
    case 9:
        Quit();
        break;
    default:
        cout << "Nieznana komenda, spróbuj tych: " << endl;
        PrintLegend();
        command = 0;
        break;
    }
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    while (true)
        MainLoop();
}
