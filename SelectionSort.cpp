#include <iostream>
#include <stdlib.h>
#include <time.h>
#define LENGTH 10

void selectionSort(int *arr)
{
    /* init delegete and temp, 
    the former is assigned by the smallest element's index, 
    and the latter is used for swapping.*/
    int delegate, temp;

    // run through every element.
    for (int i = 0; i < LENGTH; i++)
    {

        // initailized delegate as i
        delegate = i;

        // run through every element after i
        for (int j = i; j < LENGTH; j++)
            // if the element is smaller than arr[i], it is currently smallest
            if (arr[j] < arr[delegate])
                delegate = j;

        // if delegate is not i, which means, there is a smaller one
        if (delegate != i)
        {
            temp = arr[i];
            arr[i] = arr[delegate];
            arr[delegate] = temp;
        }
    }
}

int main(void)
{
    // init an array
    int *arr = new int[LENGTH];
    // init random seed
    srand(time(0));
    for (int i = 0; i < LENGTH; i++)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    selectionSort(arr);
    for (int i = 0; i < LENGTH; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
