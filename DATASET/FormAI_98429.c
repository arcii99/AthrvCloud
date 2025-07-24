//FormAI DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>

int uniqueSearch(int arr[], int n, int x) {
    int i;
    int found = 0;
    
    for(i=0; i<n; i++) {
        if(arr[i] == x) {
            found = 1;
            break;
        }
    }
    
    if(found == 1) {
        return i;
    }
    else {
        return -1;
    }
}

int main() {
    int arr[] = {10, 7, 3, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 6;
    
    int result = uniqueSearch(arr, n, x);
    if(result == -1) {
        printf("Element not found in array.\n");
    }
    else {
        printf("Element found at index %d.\n", result);
    }
    
    return 0;
}