//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>

int find_element(int arr[], int n, int ele) {
    // loop through the array to find the element
    for(int i=0; i<n; i++) {
        if(arr[i] == ele) {
            return i; // if found return index
        }
    }
    return -1; // if not found return -1
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int ele;
    printf("Enter the element to search: ");
    scanf("%d", &ele);

    int index = find_element(arr, n, ele);
    if(index == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    return 0;
}