//FormAI DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
int linearSearch(int arr[], int n, int target) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 8, 1, 3, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int index = linearSearch(arr, n, target);
    if (index != -1) {
        printf("Found %d at index %d\n", target, index);
    } else {
        printf("%d not found in the array\n", target);
    }
    return 0;
}