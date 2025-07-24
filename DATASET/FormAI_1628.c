//FormAI DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>

int BinarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;
 
    while (high >= low) {
        mid = (high + low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(void)
{
    int n, key, res;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in ascending order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    res = BinarySearch(arr, n, key);
    if (res == -1) {
        printf("Element not found in array.\n");
    }
    else {
        printf("Element found at index %d.\n", res);
    }
    return 0;
}