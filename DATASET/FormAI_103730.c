//FormAI DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include<stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;

    int index = search(arr, n, x);

    if (index == -1)
        printf("Element %d is not present in the array\n", x);
    else
        printf("Element %d is present at index %d\n", x, index);
    return 0;
}