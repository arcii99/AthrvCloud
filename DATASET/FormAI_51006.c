//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>

int search(int arr[], int n, int x)
{
    int i = 0;
    int j = n - 1;
    int mid;
    
    while (i <= j) {
        mid = (i + j) / 2;
        
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            i = mid + 1;
        }
        else {
            j = mid - 1;
        }
    }
    
    return -1;
}

int main()
{
    int arr[] = { 2, 4, 5, 7, 8, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int result = search(arr, n, x);
    
    if (result == -1) {
        printf("%d not found in the array.\n", x);
    }
    else {
        printf("%d found at index %d in the array.\n", x, result);
    }
    
    return 0;
}