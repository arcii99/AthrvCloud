//FormAI DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main(){
    int i, j, temp;

    // Declare two arrays
    int arr1[SIZE];
    int arr2[SIZE];

    // Fill both arrays with random numbers
    srand(time(NULL));
    for(i=0; i<SIZE; i++){
        arr1[i] = rand();
        arr2[i] = rand();
    }

    // Benchmarking the first loop
    clock_t begin = clock();
    for(i=0; i<SIZE-1; i++){
        for(j=0; j<SIZE-i-1; j++){
            if(arr1[j]>arr1[j+1]){
                temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
        }
    }
    clock_t end = clock();

    printf("Time taken for first loop: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

    // Benchmarking the second loop
    begin = clock();
    for(i=0; i<SIZE-1; i++){
        for(j=0; j<SIZE-i-1; j++){
            if(arr2[j]>arr2[j+1]){
                temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    }
    end = clock();

    printf("Time taken for second loop: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

    // Check if both arrays are sorted correctly
    for(i=0; i<SIZE-1; i++){
        if(arr1[i]>arr1[i+1]){
            printf("Error in first array sorting\n");
            break;
        }
    }

    for(i=0; i<SIZE-1; i++){
        if(arr2[i]>arr2[i+1]){
            printf("Error in second array sorting\n");
            break;
        }
    }

    return 0;
}