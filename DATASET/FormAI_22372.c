//FormAI DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 1, 4, 6, 7, 9, 11, 14, 16, 19, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    int index = search(arr, n, x);
    if(index == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index: %d\n", index);
    }
    return 0;
}