//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>

int linearSearch(int arr[], int size, int target);

int main() {
    int size, target, result;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element to be searched: ");
    scanf("%d", &target);
    result = linearSearch(arr, size, target);
    if (result == -1) {
        printf("The target element is not present in the array");
    } else {
        printf("The target element is present at index %d", result);
    }
    return 0;
}

int linearSearch(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}