#include <iostream>
#include <stdlib.h>
#include <time.h>
#define LENGTH 20

// Generate an array contains random numbers
void genIntArr(int *arr)
{
    srand(time(0));
    for (int i = 0; i < LENGTH; i++)
        arr[i] = rand() % 100;
}

// Bubble Sort
void bubbleSort(int *arr)
{
    // a variable indicates whether arr is sorted, and a temp for swapping.
    int allSorted = true, temp;

    // if every element is not in their place, repeatedly check them.
    do
    {
        // init as true;
        allSorted = true;

        /*
        check every element in arr, if there is a condition that
        nearby two elements are not sorted, then swap them
        */
        for (int i = 1; i < LENGTH; i++)
            if (arr[i - 1] > arr[i])
            {
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                allSorted = false;
            }
    } while (!allSorted);

    std::cout << "Sorting complete" << std::endl;
}

int main(void)
{
    int *arr = new int[LENGTH];
    genIntArr(arr);

    for (int i = 0; i < LENGTH; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    bubbleSort(arr);

    for (int i = 0; i < LENGTH; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
