//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>

/* Function to perform binary search on the given array */
int binarySearch(int arr[], int l, int r, int x)
{
    while(r >= l){
        int mid = l + (r - l)/2;
        
        if(arr[mid] == x){
            return mid;
        }
        
        if(arr[mid] > x){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 16;
    int index = binarySearch(arr, 0, n-1, x);
    
    if(index == -1){
        printf("%d not found in the array", x);
    }else{
        printf("%d found at index %d", x, index);
    }
    
    return 0;
}