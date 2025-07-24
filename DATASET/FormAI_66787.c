//FormAI DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key){
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    //sorted array
    int n = sizeof(arr) / sizeof(int);
    int key = 9;
    int result = binarySearch(arr, 0, n-1, key);
    if(result == -1){
        printf("Element not present in array!\n");
    }
    else{
        printf("Element found at index: %d\n", result);
    }
    return 0;
}