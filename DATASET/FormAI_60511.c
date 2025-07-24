//FormAI DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>

/* Function to search an element in an array */
int search(int arr[], int n, int x) {
    int i;
    for(i=0; i<n; i++) {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int x = 30;
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = search(arr, n, x);

    if(result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
    return 0;
}