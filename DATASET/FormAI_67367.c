//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Alan Touring
#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;   // Return the index of the element if found
    }
    return -1;  // Return -1 if element not found
}

int main() {
    int arr[] = {1, 5, 3, 8, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int pos = linearSearch(arr, size, key);

    if (pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", pos);

    return 0;
}