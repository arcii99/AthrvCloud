//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int l, int r, int x) {
    if (r >= l) {
        printf("Current sub-array to check: [");
        for (int i = l; i <= r; i++) {
            printf("%d", arr[i]);
            if (i != r) printf(", ");
        }
        printf("]\n");
        
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == x) {
            printf("%d found at index %d\n", x, mid);
            return mid;
        }
        
        if (arr[mid] > x) {
            printf("%d is smaller than %d, searching in the left sub-array.\n", x, arr[mid]);
            return binary_search(arr, l, mid - 1, x);
        }
        
        printf("%d is greater than %d, searching in the right sub-array.\n", x, arr[mid]);
        return binary_search(arr, mid + 1, r, x);
    }
    
    printf("%d not found in the array.\n", x);
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    binary_search(arr, 0, n - 1, x);
    
    return 0;
}