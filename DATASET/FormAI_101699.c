//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>

/* Artistic Searching Algorithm */
/* A searching algorithm can also be beautiful if it balances efficiency and elegance. */

int artistic_search(int arr[], int target, int size) {
    int mid, left = 0, right = size - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == target) {
            printf("Target found! Congratulations!\n");
            return mid;
        }
        else if (arr[mid] > target) {
            printf("We shall search the left half of the array...\n");
            right = mid - 1;
        }
        else {
            printf("We shall search the right half of the array...\n");
            left = mid + 1;
        }
    }
    printf("Target not found... Try another number.\n");
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    printf("Please enter a number to search for:\n");
    scanf("%d", &target);
    int index = artistic_search(arr, target, size);
    if (index != -1) {
        printf("The target is located at index %d in the array.\n", index);
    }
    return 0;
}