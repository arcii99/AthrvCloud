//FormAI DATASET v1.0 Category: Sorting ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int len) {

    // Entering a loop
    for(int i=0; i<len-1; i++) {

        // Iterating through an array
        for(int j=0; j<len-i-1; j++) {

            // If current element is greater than the next,
            // then swap those two elements
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Main function
int main() {

    // Generating random seed
    srand(time(NULL));

    // Defining the length of the array
    int len = 10;

    // Creating an array of random integers
    int arr[len];
    for(int i=0; i<len; i++){
        arr[i] = rand() % 100;
    }

    // Printing the unsorted array
    printf("Unsorted Array:\n");
    for(int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }

    // Performing bubble sort
    bubbleSort(arr, len);

    // Printing the sorted array
    printf("\nSorted Array:\n");
    for(int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }

    // Exiting the program
    return 0;
}