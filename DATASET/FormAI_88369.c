//FormAI DATASET v1.0 Category: Sorting ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input array
#define MAX_LENGTH 100

// Define the size of each element in the input array
#define ELEMENT_SIZE sizeof(int)

// Define the sorting function
void sort_array(int *arr, int n) {
    int i, j, temp;

    // Perform Bubble Sort on the input array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_LENGTH];
    int num_elements = 0, i = 0;

    // Get the input array from the user
    printf("Enter the elements of the array (maximum %d elements, q to quit):\n", MAX_LENGTH);
    while (num_elements < MAX_LENGTH && scanf("%d", &arr[num_elements++]) == 1);

    // Sort the input array using the sort_array() function
    sort_array(arr, num_elements);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}