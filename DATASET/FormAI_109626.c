//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {25, 45, 56, 67, 89, 90, 101};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 90;
    int result = search(arr, n, x);
    if(result == -1) {
        printf("Element is not found.");
    } else {
        printf("Element is found at index %d",result);
    }
    return 0;
}