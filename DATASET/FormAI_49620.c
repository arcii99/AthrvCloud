//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate an array of random integers between 1 and 100
    int arr[MAX];
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Sort the array using bubble sort algorithm
    for (int i = 0; i < MAX - 1; i++) {
        int flag = 0;
        for (int j = 0; j < MAX - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap two adjacent elements if they are in wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; // Set flag to indicate that a swap was made
            }
        }
        if (flag == 0) {
            // If no swaps were made in a pass, the array is already sorted
            break;
        }
    }

    // Print the sorted array in reverse order
    for (int i = MAX - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}