//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>

// Function that takes an array and its size, and the element to search
int linearSearch(int arr[], int size, int x) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == x) // If element found, return its index
            return i;
    }
    return -1; // Return -1 if element is not found
}

int main() {
    int arr[] = {2, 5, 8, 13, 17, 20, 25};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = 17;

    int index = linearSearch(arr, size, x);

    if (index == -1)
        printf("Element %d not found in array!", x);
    else
        printf("Element %d found at index %d", x, index);

    return 0;
}