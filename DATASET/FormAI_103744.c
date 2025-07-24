//FormAI DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include<stdio.h>

int search(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            low = mid + 1;

        else high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[10], n, target, i;

    printf("Enter the size of the array (max 10): ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    int result = search(arr, n, target);

    if (result == -1) {
        printf("Element not found \n");
    } else {
        printf("Element found at index: %d\n", result);
    }

    return 0;
}