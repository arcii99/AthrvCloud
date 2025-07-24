//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdbool.h>

int linearSearch(int array[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1; // key not found
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    int key;
    printf("Enter the search key: ");
    scanf("%d", &key);

    int result = linearSearch(array, size, key);

    if (result == -1) {
        printf("The element %d is not found in the array.", key);
    } else {
        printf("The element %d is found at index %d in the array.", key, result);
    }
    return 0;
}