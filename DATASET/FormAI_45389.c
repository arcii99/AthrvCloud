//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main()
{
    int i;
    int *arr = (int *) malloc(SIZE * sizeof(int)); // allocate memory dynamically

    // populate the array with random integers between 1 and 1000
    srand(time(NULL));
    for(i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000 + 1;

    // perform bubble sort on the array
    int temp, j;
    for(i = 0; i < SIZE-1; i++)
    {
        for(j = 0; j < SIZE-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // print out the sorted array
    for(i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    free(arr); // free dynamically allocated memory

    return 0;
}