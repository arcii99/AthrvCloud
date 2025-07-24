//FormAI DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>

int futuristicSearch(int arr[], int low, int high, int x) {
    int mid1, mid2;

    while (low <= high) {
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;

        if (arr[mid1] == x) {
            return mid1;
        }
        else if (arr[mid2] == x) {
            return mid2;
        }
        else if (x < arr[mid1]) {
            high = mid1 - 1;
        }
        else if (x > arr[mid2]) {
            low = mid2 + 1;
        }
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = futuristicSearch(arr, 0, n - 1, x);

    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);
    return 0;
}