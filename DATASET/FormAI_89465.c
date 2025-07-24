//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>

/**
* This is my unique C searching algorithm,
* It searches for an element in an array with a given value.
* It returns the index of the first occurrence of the element in the array
* or -1 if the element is not found.
*/

int search(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    int arr[] = { 5, 10, 15, 20, 25 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 15;
    int index = search(arr, size, value);
    
    if (index == -1) {
        printf("Value %d not found in the array.\n", value);
    } else {
        printf("Value %d found at index %d.\n", value, index);
    }

    return 0;
}