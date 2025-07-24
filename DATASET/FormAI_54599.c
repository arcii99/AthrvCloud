//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
// Knuth-inspired searching algorithm
#include <stdio.h>

int search(int arr[], int n, int x) {
    // initialize variables
    int left = 0, right = n - 1, m;
    
    while (left <= right) {
        m = left + (right - left) / 2;  // calculate middle index
        
        if (arr[m] == x) {  // if element found
            return m;
        } else if (arr[m] < x) {  // if element is on right side
            left = m + 1;
        } else {  // if element is on left side
            right = m - 1;
        }
    }
    
    // if element not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x, result;
    
    // get element to search from user
    printf("Enter element to search: ");
    scanf("%d", &x);
    
    // perform search
    result = search(arr, n, x);
    
    // display result
    if (result == -1) {
        printf("%d not found in array", x);
    } else {
        printf("%d found in array at index %d", x, result);
    }
    
    return 0;
}