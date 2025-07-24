//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random integers
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to perform a bubble sort on an array of integers
void bubble_sort(int arr[], int len) {
    int temp;
    for(int i=0; i<len-1; i++) {
        for(int j=0; j<len-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    const int n = 10000;
    int arr[n];

    // Generate random array of integers
    for(int i=0; i<n; i++) {
        arr[i] = random_int(1, n);
    }

    // Perform bubble sort on the array
    bubble_sort(arr, n);

    // Print sorted array
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}