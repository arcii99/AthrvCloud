//FormAI DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Let's sort this array!\n");

    srand(time(NULL)); // seed the random number generator

    int arr[10];
    printf("Unsorted Array: ");
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100; // generate random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorting in progress...");
    for (int i = 0; i < 9; i++) { // bubble sort algorithm
        for (int j = 0; j < 9-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Hooray! The array is now sorted!\n");
    return 0;
}