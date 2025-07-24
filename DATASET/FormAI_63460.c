//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == x)
            return i;
     }
     return -1;
}

int main() {
    int arr[] = {5, 7, 2, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    int result = search(arr, n, x);

    if(result == -1)
        printf("Element %d was not found in the array", x);
    else
        printf("Element %d was found at index %d", x, result);
}