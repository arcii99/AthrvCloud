//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include<stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 5, 9, 22, 36, 47, 68 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int x;
    printf("Enter the element to be searched:\n");
    scanf("%d", &x);

    int result = search(arr, n, x);

    if (result == -1) {
        printf("Element is not present in array.");
    } else {
        printf("Element is present at index %d", result);
    }
    return 0;
}