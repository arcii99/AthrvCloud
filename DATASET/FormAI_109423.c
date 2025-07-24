//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>

int complexSearch(int arr[], int length, int key) {

    int left = 0;
    int right = length - 1;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == key)
            return middle;

        if (arr[middle - 1] < arr[middle]) {
            if (key < arr[middle - 1] || key > arr[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }
        else {
            if (key < arr[middle] || key > arr[middle + 1])
                left = middle + 1;
            else
                right = middle - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = { 3, 4, 5, 6, 1, 2 };
    int key = 5;
    int length = sizeof(arr) / sizeof(arr[0]);
    int result = complexSearch(arr, length, key);

    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);

    return 0;
}