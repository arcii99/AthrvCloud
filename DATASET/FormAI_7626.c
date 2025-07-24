//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
   if (r >= l) {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  
            return mid;
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
        else
            return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

int main() {

    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 13;
    int result = binarySearch(arr, 0, n-1, x);

    if (result == -1) 
        printf("Element not found!\n");
    else
        printf("Element found at index %d\n", result);
    
    return 0;
}