//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int linear_search(int *arr, int key, int size) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(int *arr, int low, int high, int key) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 50;
    }
    printf("The array is:\n");
    print_array(arr, SIZE);

    int key = 20;
    printf("Searching for %d using linear search...\n", key);
    int index = linear_search(arr, key, SIZE);
    if(index == -1) {
        printf("The key %d was not found in the array using linear search.\n", key);
    }
    else {
        printf("The key %d was found at index %d in the array using linear search.\n", key, index);
    }

    printf("\nSorting the array...\n");
    for(int i = 0; i < SIZE - 1; i++) {
        for(int j = i + 1; j < SIZE; j++) {
            if(arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf("The sorted array is:\n");
    print_array(arr, SIZE);

    key = 30;
    printf("\nSearching for %d using binary search...\n", key);
    index = binary_search(arr, 0, SIZE - 1, key);
    if(index == -1) {
        printf("The key %d was not found in the array using binary search.\n", key);
    }
    else {
        printf("The key %d was found at index %d in the array using binary search.\n", key, index);
    }

    return 0;
}