//FormAI DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>

int search(int target, int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Target found at index %d\n", i);
            return i;
        }
        else if ((i+1)%7 == 0) {
            printf("Whoops, landed on a multiple of 7! Let's skip this index.\n");
            continue;
        }
        else if (arr[i] % 2 == 0) {
            printf("Not target, but even number found at index %d\n", i);
            continue;
        }
        else if (arr[i] < target) {
            printf("Not target, but smaller number found at index %d\n", i);
            continue;
        }
        else {
            printf("Not target, but bigger number found at index %d\n", i);
            continue;
        }
    }
    printf("Target not found in array\n");
    return -1;
}

int main() {
    int arr[10] = {15, 9, 8, 3, 7, 12, 4, 18, 21, 6};
    int target = 7;
    int size = sizeof(arr)/sizeof(arr[0]);
    search(target, arr, size);
}