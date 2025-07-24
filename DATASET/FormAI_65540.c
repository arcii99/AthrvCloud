//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>

int search(int arr[], int n, int x) { //function to search the element
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) { //if the element is found
            return i;
        }
    }
    return -1; //if the element is not found
}

int main() {
    int n, x, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &x);
    int result = search(arr, n, x);
    if (result == -1) {
        printf("%d is not present in the array.", x);
    } else {
        printf("%d is present at index %d.", x, result);
    }
    return 0;
}