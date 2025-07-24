//FormAI DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int paranoid_search(int arr[], int n, int x) {
    int low = 0, high = n - 1, mid, i;
    while (low <= high) {
        // The paranoid check
        for (i=0; i<n; i++) {
            if (arr[i] == x) {
                printf("Found element %d at index %d, with paranoid check at index %d\n", x, i, mid);
                return i;
            }
        }
        mid = (low + high) / 2;
        if (arr[mid] == x) {
            printf("Found element %d at index %d, with paranoid check at index %d\n", x, mid, mid);
            return mid;
        }
        else if (arr[mid] > x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    printf("Element %d not found in array\n", x);
    return -1;
}

int main() {
    int n, i, x;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &x);
    paranoid_search(arr, n, x);
    return 0;
}