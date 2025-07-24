//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

int linear_search(int arr[], int n, int x) {
    for(int i=0; i<n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int left, int right, int x) {
    while(left <= right) {
        int mid = left + (right - left)/2;
        
        if(arr[mid] == x) {
            return mid;
        }
            
        if(arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;   
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 12, 14, 18, 22, 33, 44, 55};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 12;
    
    printf("Array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    int result_linear = linear_search(arr, n, x);        
    if(result_linear == -1) {
        printf("Linear search: Element not present in the array\n");
    }
    else {
        printf("Linear search: Element found at index %d\n", result_linear);
    }
    
    int result_binary = binary_search(arr, 0, n-1, x);        
    if(result_binary == -1) {
        printf("\nBinary search: Element not present in the array\n");
    }
    else {
        printf("\nBinary search: Element found at index %d\n", result_binary);
    }
    
    return 0;
}