#include "Sort.h"
using namespace std;

int main()
{
    bool ascendent = false;
    cout << "s1 :: " << endl << endl;
    Sort s1{ 9, 13, 17, 4, 25, 36, 90, 37, 39, 45 };
    cout << "Nesortat : ";
    s1.Print();
    s1.QuickSort(ascendent);
    cout << "Sortat : ";
    s1.Print();
    cout << "Elementul de pe pozitia 5 : ";
    cout << s1.GetElementFromIndex(5);
    cout << endl;
    cout << "Numarul total de elemente : ";
    cout << s1.GetElementsCount();
    cout << endl;

    cout << endl << "-------------------------------------------" << endl;
    Sort s2{ 10, 100, 500 };
    s2.InsertSort(ascendent);
    cout << "s2 Sortat : ";
    s2.Print();

    cout << endl << "-------------------------------------------" << endl;
    int v[] = { 14, 7, 23, 20, 35, 39, 40, 11, 40, 33, 99, 88 };
    Sort s3{ v,12 };
    s3.BubbleSort(ascendent);
    cout << "s3 Sortat : ";
    s3.Print();

    cout << endl << "-------------------------------------------" << endl;
    char numere[]= "13;56;34;24;12;24;66;77;65;99";
    Sort s4{ numere };
    s4.QuickSort(ascendent);
    cout << "s4 Sortat : ";
    s4.Print();

    cout << endl << "-------------------------------------------" << endl;
}
