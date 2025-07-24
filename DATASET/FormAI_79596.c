//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>

int linear_search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    
    int result = linear_search(arr, size, key);
    
    if (result == -1) {
        printf("Element %d not found in the array.", key);
    } else {
        printf("Element %d found at index %d.", key, result);
    }
    
    return 0;
}