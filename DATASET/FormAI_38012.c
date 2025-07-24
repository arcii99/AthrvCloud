//FormAI DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>

int optimizedLinearSearch(int arr[], int n, int key) {
    int index = -1;
    for(int i=0; i<n; i++) {
        if(arr[i]==key) {
            index = i;
            break;
        }
    }
    return index;
}

int main() {
    int arr[] = {1, 2, 5, 10, 15, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int index = optimizedLinearSearch(arr, n, key);
    if(index==-1) {
        printf("Element not found.\n");
    }
    else {
        printf("Element found at index %d\n", index);
    }
    return 0;
}