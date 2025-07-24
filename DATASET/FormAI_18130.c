//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000  // define size of array
#define MAX_NUM 10000       // define maximum number to fill array

int main()
{
    int i, j, temp, a[ARRAY_SIZE];
    clock_t start, end;     // variables to hold time values
    double time_used;
    
    printf("----- Benchmarking program -----\n");
    printf("Filling array with random numbers...\n");
    
    srand(time(NULL));     // seed random number generator with current time
    
    // fill array with random numbers
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        a[i] = rand() % MAX_NUM;
    }
    
    printf("Sorting array...\n");

    start = clock();    // record starting time
    
    // bubble sort algorithm
    for(i = 0; i < ARRAY_SIZE-1; i++)
    {
        for(j = 0; j < ARRAY_SIZE-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    end = clock();   // record ending time

    printf("Array sorted successfully!\n\n");

    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;   // calculate time used for sorting

    printf("Time taken to sort the array : %f seconds\n", time_used);

    return 0;   // end of program
}