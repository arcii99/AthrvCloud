//FormAI DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>

void search(int arr[], int n, int key) {
    int i, found = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;
            break;
        }
    }
    if(found) {
        printf("Key found at index %d\n", i);
    }
    else {
        printf("Key not found in the array\n");
    }
}

int main() {
    int arr[100], n, i, key;
    
    // Input size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    // Input array elements
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input search key
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    // Perform search
    search(arr, n, key);
    return 0;
}