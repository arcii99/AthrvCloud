//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 3, 1, 6, 2, 10, 0, 15, 24, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 15;

    int result = linearSearch(arr, n, x);

    if(result == -1) {
        printf("%d not found in the array.\n", x);
    } else {
        printf("%d found at index %d.\n", x, result);
    }

    return 0;
}