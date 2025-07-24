//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));     // Required to generate random numbers using rand() function
 
    int n = 10;     // Number of elements in array
    int arr[n];     // Array to store the elements
    int i, j, temp;
 
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);     // Taking input from user
    }
 
    printf("\nArray before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);     // Printing the unsorted array
    }
 
    // Implementing Selection Sort Algorithm
    for (i = 0; i < n - 1; i++) {
        int min = i;     // Assume the first element is the minimum
 
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {     // If any other number is smaller than the assumed minimum, swap them
                min = j;
            }
        }
 
        if (min != i) {     // Swap two elements
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
 
    printf("\n\nArray after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);     // Printing the sorted array
    }
 
    return 0;
}