//FormAI DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>

int binary_search(int arr[], int n, int x) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int interpolation_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);
        if (arr[pos] == x) {
            return pos;
        }
        if (arr[pos] < x) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 10;
    int b_result = binary_search(arr, n, x);

    if (b_result == -1) {
        printf("Element not found in binary search.\n");
    } else {
        printf("Element found at index %d in binary search.\n", b_result);
    }

    int i_result = interpolation_search(arr, n, x);

    if (i_result == -1) {
        printf("Element not found in interpolation search.\n");
    } else {
        printf("Element found at index %d in interpolation search.\n", i_result);
    }

    return 0;
}