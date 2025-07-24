//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main() {
    int arr[] = {4, 2, 5, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int x = 5;
    int result = search(arr, n, x);
    if (result == -1)
        printf("%d was not found in the array.", x);
    else
        printf("%d was found at index %d.", x, result);
    
    return 0;
}