//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size, key, searchIndex;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Read the array elements
    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the key to be searched
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    // Perform linear search
    searchIndex = linearSearch(arr, size, key);

    // Print the result
    if (searchIndex != -1) {
        printf("Element %d found at index %d\n", key, searchIndex);
    } else {
        printf("Element %d not found\n", key);
    }

    return 0;
}