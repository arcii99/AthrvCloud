//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

int brave_search(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        printf("I am brave enough to search at index %d\n", mid);

        if (arr[mid] == target) {
            printf("I found %d at index %d!\n", target, mid);
            return mid;
        } else if (arr[mid] < target) {
            printf("%d is not here. I will look to the right!\n", target);
            left = mid + 1;
        } else {
            printf("%d is not here. I will look to the left!\n", target);
            right = mid - 1;
        }
    }

    printf("I searched bravely, but could not find %d\n", target);
    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 10, 14, 17, 21, 28};
    int n = sizeof(arr) / sizeof(int);
    int target = 17;

    int result = brave_search(arr, n, target);

    if (result == -1) {
        printf("I am sorry. I could not find %d\n", target);
    }

    return 0;
}