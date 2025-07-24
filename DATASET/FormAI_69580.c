//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

int linear_search(int *arr, int size, int key) {
    for(int i=0; i<size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d integers:\n", n);
    
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the number to search: ");
    scanf("%d", &key);
    
    int pos = linear_search(arr, n, key);
    
    if(pos == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at position: %d\n", pos+1);
    }
    
    return 0;
}