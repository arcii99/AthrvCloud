//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int cryptic_search(int *arr, int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            printf("Key found at index %d!\n", mid);
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    printf("Key not found.\n");
    return -1;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int*) malloc(n * sizeof(int));

    printf("\nEnter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the key to search: ");
    int key;
    scanf("%d", &key);

    cryptic_search(arr, n, key);

    free(arr);
    return 0;
}