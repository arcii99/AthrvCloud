//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>

int binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int arr[10], key, n;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = binary_search(arr, n, key);
    if (index == -1)
        printf("Element not found!\n");
    else
        printf("Element found at index %d\n", index);
    return 0;
}