//FormAI DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

// Generate random numbers between 0 and 99999 and store them in an array
void generateRandomNumbers(int arr[]) {
    srand(time(NULL));
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100000;
    }
}

// Print the array
void printArray(int arr[]) {
    printf("Array: ");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Decentralized linear search
int decentralizedLinearSearch(int arr[], int key) {
    int chunk_size = ARRAY_SIZE / 8; // Divide the array into 8 chunks
    int index;
    #pragma omp parallel for
    for(int i = 0; i < 8; i++) {
        int start = i * chunk_size;
        int end = (i + 1) * chunk_size;
        for(int j = start; j < end; j++) {
            if(arr[j] == key) {
                index = j;
            }
        }
    }
    return index;
}

int main() {
    int arr[ARRAY_SIZE];
    generateRandomNumbers(arr);
    printArray(arr);
    int key = 78964;
    int index = decentralizedLinearSearch(arr, key);
    if(index >= 0) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }
    return 0;
}