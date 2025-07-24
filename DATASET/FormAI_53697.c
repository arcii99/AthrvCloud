//FormAI DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

/* Modified binary search algorithm for integer target in a sorted list */
int binary_search(int *list, int size, int target) {
    int start = 0;
    int end = size - 1;
    int mid = end / 2;

    while (start <= end) {
        if (list[mid] == target) {
            return mid;
        }
        else if (list[mid] < target) {
            start = mid + 1;
        }
        else if (list[mid] > target) {
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }

    return -1; /* Target not found */
}

/* Main program to test binary_search function */
int main(void) {
    int list[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(list) / sizeof(list[0]);
    int target = 16;

    printf("Searching for %d in list:", target);
    for (int i = 0; i < size; i++) {
        printf(" %d", list[i]);
    }
    printf("\n");

    int index = binary_search(list, size, target);

    if (index == -1) {
        printf("Target %d not found in list.\n", target);
    }
    else {
        printf("Target %d found at index %d in list.\n", target, index);
    }

    return EXIT_SUCCESS;
}