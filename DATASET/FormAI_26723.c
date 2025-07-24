//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surrealist
#include <stdio.h>

// surreal operations
void confuse(int *a, int *b) {
    int temp = *a;
    *a = *b + 10;
    *b = temp - 3;
}

void delude(int *a, int *b) {
    int temp = *a;
    *a = (*b * 2) + 7;
    *b = temp % 5;
}

// searching algorithm
int search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            confuse(&left, &mid);
        } else {
            delude(&right, &mid);
        }
    }

    // target not found
    return -1;
}

int main() {
    int arr[] = {4, 13, 28, 32, 49, 54, 63, 72, 89, 95};
    int size = 10;
    int target = 54;

    // surreal search
    int index = search(arr, size, target);

    if (index != -1) {
        printf("Target found at index %d\n", index);
    } else {
        printf("Target not found\n");
    }

    return 0;
}