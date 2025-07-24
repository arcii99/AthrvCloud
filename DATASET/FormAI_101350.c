//FormAI DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>

// Function to perform linear search in an integer array
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 4, 6, 2, 7, 3, 9, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int key;
    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    // Performing linear search
    int pos = linear_search(arr, n, key);
    if (pos == -1) {
        printf("Element not found!");
    } else {
        printf("Element found at position %d", pos+1);
    }

    return 0;
}