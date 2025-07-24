//FormAI DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50

// Function to create an array with random elements
int *create_array() {
    int *arr = malloc(sizeof(int) * ARRAY_SIZE);
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Function to search for an element in an array using retro style algorithm
int retro_search(int *arr, int key) {
    int i = 0;
    while (i < ARRAY_SIZE) {
        if (arr[i] == key) {
            return i;
        }
        i++;
    }
    return -1;
}

int main() {
    int *arr = create_array();
    int key = 55;
    int index = retro_search(arr, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    free(arr);
    return 0;
}