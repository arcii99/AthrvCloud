//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1000000 // size of the array

void insertion_sort(int arr[], int n);

int main()
{
    int arr[SIZE];
    int i;

    srand(time(0)); // seeding the random number generator

    // generating random numbers and populating the array
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = rand();
    }

    clock_t begin = clock(); // start the clock

    insertion_sort(arr, SIZE); // calling the insertion sort function

    clock_t end = clock(); // stop the clock

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // calculate the time taken

    printf("Time taken: %f seconds.", time_spent);

    return 0;
}

// function to perform insertion sort
void insertion_sort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}