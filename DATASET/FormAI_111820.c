//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 5, 1, 9, 0, 3, 6, 4};
    int n = sizeof(arr) / sizeof(int);
    int key = 3;
    int result = linear_search(arr, n, key);

    printf("Before sorting : ");
    display(arr, n);

    if(result == -1) {
        printf("Element %d not found in the array\n", key);
    } else {
        printf("Element %d found at index %d in the array\n", key, result);
    }

    int temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("After sorting : ");
    display(arr, n);

    result = linear_search(arr, n, key);
    if(result == -1) {
        printf("Element %d not found in the array\n", key);
    } else {
        printf("Element %d found at index %d in the array\n", key, result);
    }

    return 0;
}