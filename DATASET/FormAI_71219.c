//FormAI DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>

// defining the size of the array
#define MAX_SIZE 10

// function to perform linear search in an array
int linearSearch(int arr[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE], i, key, index;
    printf("Enter %d integers: ", MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    index = linearSearch(arr, MAX_SIZE, key);
    if (index != -1) {
        printf("%d found at index %d\n", key, index);
    } else {
        printf("%d not found in the array\n", key);
    }
    return 0;
}