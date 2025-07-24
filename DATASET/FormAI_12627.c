//FormAI DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>

/* Visionary-style searching algorithm */
int visionary_search(int arr[], int n, int key) {
    int i, j, k;

    /* Loop through the array */
    for (i = 0; i < n; i = k + 1) {

        /* Check if the current element is the key */
        if (arr[i] == key) {
            return i;
        }

        /* Increment k until value at index k is greater than key or we reach the end of the array */
        for (j = i, k = i + 1; k < n && arr[k] <= key; j = k, k *= 2);

        /* Perform binary search between array indices j and k */
        int m;
        while (j <= k) {
            m = (j + k) / 2;

            if (arr[m] < key) {
                j = m + 1;
            }
            else if (arr[m] > key) {
                k = m - 1;
            }
            else {
                return m;
            }
        }
    }

    /* Key not found */
    return -1;
}

int main() {
    /* A sorted array to search in */
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /* Search for the value 5 in the array */
    int key = 5;
    int index = visionary_search(arr, sizeof(arr)/sizeof(int), key);

    if (index == -1) {
        printf("Value not found in array.\n");
    }
    else {
        printf("Value found at index: %d\n", index);
    }

    return 0;
}