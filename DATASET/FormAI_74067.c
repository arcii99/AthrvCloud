//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int sorted_array[], int start, int end, int x) {
    while (start <= end) {
        int mid = (start + end) / 2;

        if (sorted_array[mid] == x) {
            return true;
        } else if (sorted_array[mid] > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return false;
}

int main() {
    int sorted_array[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(sorted_array) / sizeof(sorted_array[0]);

    printf("The sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    int search_for = 11;
    if (binarySearch(sorted_array, 0, size - 1, search_for)) {
        printf("%d is found in the array.\n", search_for);
    } else {
        printf("%d is not found in the array.\n", search_for);
    }

    search_for = 10;
    if (binarySearch(sorted_array, 0, size - 1, search_for)) {
        printf("%d is found in the array.\n", search_for);
    } else {
        printf("%d is not found in the array.\n", search_for);
    }

    return 0;
}