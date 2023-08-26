#include <iostream>
#include <algorithm>
using namespace std;
// ********************************************************
void binarySearch(int arr[], int size, int ch)
{
    bool nf = true;
    cout << endl;
    cout << endl;
    int s = 0, e = size - 1;
    int i = 1;
    while (s <= e)
    {
        cout << "Pass " << i++ << endl;
        int m = (s + e) / 2;
        cout << "Comparing mid element '" << arr[m] << "' with '" << ch << "'" << endl;
        if (arr[m] == ch)
        {
            cout << "Since '" << arr[m] << "' == '" << ch << "' Element found" << endl;
            nf = false;
            break;
        }
        if (arr[m] < ch)
        {
            cout << "Since '" << arr[m] << "' < '" << ch << "' ignore left half array" << endl;
            s = m + 1;
        }
        else
        {
            cout << "Since '" << arr[m] << "' > '" << ch << "' ignore right half array" << endl;
            e = m - 1;
        }
        cout << endl;
        cout << endl;
    }
    if (nf)
    {
        cout << "'" << ch << "' not found in array" << endl;
    }
}

void modifiedBinarySearch(int arr[], int size, int ch)
{
    bool nf = true;
    cout << endl;
    cout << endl;
    int s = 0, e = size - 1;
    int i = 1;
    while (s <= e)
    {
        cout << "Pass " << i++ << endl;
        int m = (s + e) / 2;
        cout << "Comparing mid element '" << arr[m] << "' with '" << ch << "'" << endl;
        if (arr[m] == ch)
        {
            cout << "Since '" << arr[m] << "' == '" << ch << "' Element found" << endl;
            nf = false;
            break;
        }
        if (arr[m] > ch)
        {
            cout << "Since '" << arr[m] << "' > '" << ch << "' ignore left half array" << endl;
            s = m + 1;
        }
        else
        {
            cout << "Since '" << arr[m] << "' < '" << ch << "' ignore right half array" << endl;
            e = m - 1;
        }
        cout << endl;
        cout << endl;
    }
    if (nf)
    {
        cout << "'" << ch << "' not found in array" << endl;
    }
}

// *********************************************************
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printComparison(int a, int b)
{
    cout << "Comparing " << b << " and " << a << ": ";
    if (a < b)
        cout << a << " is minimum" << endl;
    else
        cout << b << " is minimum" << endl;
}
// *************************************************
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int check = 0;
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            printComparison(arr[j], key);
            arr[j + 1] = arr[j];
            --j;
            check++;
        }
        if (check == 0)
        {
            cout << " No swapping,already in correct position :" << endl;
        }
        arr[j + 1] = key;

        // Print the current step
        cout << "Step " << i << ": ";
        printArray(arr, size);
        cout << endl;
    }
}
// *********************************************************************

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            // if (j != (size - 1))
            printComparison(arr[j], arr[minIndex]);
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
        }

        // Print the minimum element for the current step
        cout << "Minimum element in step " << i + 1 << ": " << arr[i] << " ( index " << i << " Swapped with element at index " << minIndex << ")" << endl;

        // Print the current step
        cout << "Step " << i + 1 << ": ";
        printArray(arr, size);
        cout << endl
             << endl;
    }
}

int main()
{
    cout << "Welcome to Sorting And Searching Algorithm Simulator" << endl;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, size);

    int choice;
    cout << "\nSelect a sorting algorithm: " << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Insertion Sort" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        selectionSort(arr, size);
        break;
    case 2:
        insertionSort(arr, size);
        break;

    default:
        cout << "Invalid choice." << endl;
        break;
    }
    cout << "do you also want a search element ?? ( y / size)";
    char c;
    cin >> c;
    switch (c)
    {
    case 'y':
        sort(arr, arr + size);
        cout << "sorted array : ";
        printArray(arr, size);
        cout << endl;
        int ch;

        cout << "Enter element you want to search: ";
        cin >> ch;
        binarySearch(arr, size, ch);
        break;

    default:
        cout << "thank you";
        break;
    }
    delete[] arr;

    return 0;
}
