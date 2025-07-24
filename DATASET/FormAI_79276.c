//FormAI DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>

int invasive_search(int arr[], int size, int target) {
    int i = 0;
    while (i < size) {
        if (arr[i] == target) {
            return i;
        } else if (arr[i] > target) {
            arr[i] = target;
            i = 0;
        } else {
            i++;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    printf("Array before search:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    int result = invasive_search(arr, size, target);

    printf("\n\nArray after search:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    if (result == -1) {
        printf("\n\nTarget %d not found.\n", target);
    } else {
        printf("\n\nTarget %d found at index %d.\n", target, result);
    }

    return 0;
}