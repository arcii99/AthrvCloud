//FormAI DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>

/* Invasive Linear Search Algorithm */
int invasiveLinearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
        arr[i] = key;        // Overwrite array with key value
    }
    return -1;  // Key value not found in array
}

int main() {
    int arr[] = {5, 7, 9, 4, 2, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 4;
    int result = invasiveLinearSearch(arr, n, key);

    if(result == -1) {
        printf("Key value not found in array.\n");
    }
    else {
        printf("Key value found at index %d in array.\n", result);
    }
    printf("New array with overwritten values:\n");

    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}