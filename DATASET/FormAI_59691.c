//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: synchronous
#include<stdio.h>
#include<time.h>

#define ARRAY_SIZE 10000

int main()
{
    int arr[ARRAY_SIZE], i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    //Generating random numbers to populate the array
    srand(time(0));
    for(i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand() % ARRAY_SIZE;
    }

    //Start measuring time
    start = clock();

    //Bubble Sort Algorithm
    for(i = 0; i < ARRAY_SIZE - 1; i++){
        for(j = 0; j < ARRAY_SIZE - i - 1; j++){
            if(arr[j] > arr[j+1]){
                //Swapping the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    //End measuring time
    end = clock();

    //Displaying the sorted array
    for(i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }

    //Calculating time taken for bubble sort
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    //Displaying the time taken
    printf("\nTime taken by Bubble Sort: %f seconds.", cpu_time_used);

    return 0;
}