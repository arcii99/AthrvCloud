//FormAI DATASET v1.0 Category: Searching algorithm ; Style: standalone
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
    int arr[] = {12, 34, 56, 67, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 67;
    int result = search(arr, n, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);
    return 0; 
}