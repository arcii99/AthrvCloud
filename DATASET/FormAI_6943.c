//FormAI DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>

/* Retro-Style Searching Algorithm */

int main() {
    int arr[] = {1, 7, 23, 54, 72, 90, 105, 127, 131, 210};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Input number to search:\n");
    int search_item;
    scanf("%d", &search_item);

    int mid = size / 2;
    int lower_bound = 0;
    int upper_bound = size - 1;

    /* Retro-Style Binary Search */
    while (lower_bound <= upper_bound) {
        int mid_val = arr[mid];
        if (mid_val == search_item) {
            printf("Found %d at position %d\n", search_item, mid+1);
            return 0;
        }
        else if (search_item < mid_val) {
            upper_bound = mid - 1;
            mid = (lower_bound + upper_bound) / 2;
        }
        else if (search_item > mid_val) {
            lower_bound = mid + 1;
            mid = (lower_bound + upper_bound) / 2;
        }
    }

    printf("Sorry, %d not found in array.\n", search_item);
    return 0;
}