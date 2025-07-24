//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
/* Statistical Sorting Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Define the size of the array

int main(void) {
    int arr[SIZE], i, j, temp;
    srand(time(NULL)); // Seed the random number generator
    printf("Generating random array of integers:\n");
    for(i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; // Generate random integers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n\nSorting array using selection sort:\n");
    for(i = 0; i < SIZE-1; i++) {
        int minIndex = i;
        for(j = i+1; j < SIZE; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    printf("Sorted array: \n");
    for(i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nSorting array using bubble sort:\n");
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array: \n");
    for(i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nSorting array using insertion sort:\n");
    for(i = 1; i < SIZE; i++) {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    printf("Sorted array: \n");
    for(i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}