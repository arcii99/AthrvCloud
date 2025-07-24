//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int n, searchValue;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter a value to be searched: ");
    scanf("%d", &searchValue);

    int resultIndex = binarySearch(arr, 0, n - 1, searchValue);

    if (resultIndex == -1) {
        printf("Sorry, value not found in array\n");
    } else {
        printf("%d found at index %d\n", searchValue, resultIndex);
    }
    return 0;
}