//FormAI DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>

#define MAX_SIZE 100

int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int i, n, key, arr[MAX_SIZE], index;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &key);
    index = linearSearch(arr, n, key);
    if (index == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at index %d\n", index);
    }
    return 0;
}