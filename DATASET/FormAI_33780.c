//FormAI DATASET v1.0 Category: Searching algorithm ; Style: automated
#include<stdio.h>

int binarySearch(int arr[], int l, int r, int x);

int main(){
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 14;
    int result = binarySearch(arr, 0, n-1, x);
    printf("Element %d is present at index %d in the array.\n", x, result);
    return 0;
}

int binarySearch(int arr[], int l, int r, int x){
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}