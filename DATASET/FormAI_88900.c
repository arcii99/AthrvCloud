//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

int main()
{
    int arr[SIZE];
    int sortedArr[SIZE];
    int temp;

    // randomly generate numbers for array
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % SIZE;
    }

    // sort array in ascending order using bubble sort algorithm
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // copy sorted array to another array
    for (int i = 0; i < SIZE; i++)
    {
        sortedArr[i] = arr[i];
    }

    // randomly assign a value in the sorted array to a variable
    int key = sortedArr[rand() % SIZE];

    // search for key in sorted array using binary search algorithm
    int low = 0;
    int high = SIZE - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (sortedArr[mid] == key)
        {
            printf("Key found at index %d\n", mid);
            break;
        }
        else if (sortedArr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return 0;
}