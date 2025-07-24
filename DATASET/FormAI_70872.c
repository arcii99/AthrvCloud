//FormAI DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>

int search(int arr[], int n, int key) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 7, 6, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int result = search(arr, n, key);
    if(result == -1) {
        printf("%d not found!\n", key);
    }
    else {
        printf("%d found at index %d\n", key, result);
    }
    return 0;
}