//FormAI DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>

/* Linear search function */
int linearSearch(int arr[], int n, int elem) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int elem;
    printf("Enter the element to be searched: ");
    scanf("%d", &elem);
    
    int index = linearSearch(arr, n, elem);
    if (index != -1) {
        printf("%d found at index %d\n", elem, index);
    } else {
        printf("%d not found in the array\n", elem);
    }
    
    return 0;
}