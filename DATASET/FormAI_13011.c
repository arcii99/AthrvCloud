//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>

/* Welcome to my sort-tastic program! 
 * Here, we'll be using the bubble sort algorithm 
 * to sort an array of integers from smallest to largest! 
 * Don't worry if you're not familiar with the algorithm, 
 * we'll go over it together. 
 * Grab a cup of coffee, put on some cheerful music, 
 * and let's get ready to sort! */

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3, 8, 4, 7}; // Our unsorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Finding the length of our array
    
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Let's start sorting! Yay!
    for (int i = 0; i < n - 1; i++) { // Let's loop through the array
        for (int j = 0; j < n - i - 1; j++) { // Let's check every element except those at the end
            if (arr[j] > arr[j+1]) { // If the current element is greater than the next one
                /* We swap them using a temporary variable.
                 * Don't worry if this is confusing, just trust the process! */
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0; // We made it to the end! Congrats on sorting the array!
}