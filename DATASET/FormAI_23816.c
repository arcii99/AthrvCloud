//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#include <stdio.h>

int search(int arr[], int low, int high, int key) {

    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) 
            return mid;

        if (arr[mid] > key) 
            return search(arr, low, mid - 1, key);

        return search(arr, mid + 1, high, key);
    }
    return -1;
}

int main() {

    int arr[] = { 3, 18, 4, 12, 7, 26, 9, 14, 5, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 5;
    int index = search(arr, 0, n - 1, key);

    if(index == -1) {
        printf("Key not found :(\n");
    }
    else {
        printf("Key found at index %d!\n", index);
    }

    return 0;
}