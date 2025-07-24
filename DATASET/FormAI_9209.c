//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: happy
#include <stdio.h>
#include <time.h>

int main() {
    printf("Welcome to the Happy Sorter Program!\n");

    // Declare an array of random integers
    int arr[100];
    srand(time(NULL));
    for(int i = 0; i < 100; i++) {
        arr[i] = rand() % 1000;
    }

    // Print the unsorted array
    printf("Unsorted Array: \n[");
    for(int i = 0; i < 99; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[99]);

    // Sort the array using the Happy Sort algorithm
    for(int i = 0; i < 99; i++) {
        for(int j = i+1; j < 100; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted Array: \n[");
    for(int i = 0; i < 99; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[99]);

    // Celebrate the successful sorting
    printf("Hooray! The array is now sorted! :D\n");
    return 0;
}