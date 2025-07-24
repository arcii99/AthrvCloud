//FormAI DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>

// function to perform C linear search
int linear_search(int arr[], int len, int target){
    for(int i=0; i<len; i++){
        if(arr[i] == target){
            return i; // return index of the target element
        }
    }
    return -1; // element not found
}

// function to perform C binary search
int binary_search(int arr[], int len, int target){
    int l = 0, r = len-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(arr[mid] == target){
            return mid; // return index of the target element
        }
        else if(arr[mid] < target){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1; // element not found
}

int main(){
    int arr[] = {2, 3, 7, 11, 15, 28, 32, 36, 41, 58, 67, 73, 89, 94, 99};
    int len = sizeof(arr)/sizeof(arr[0]);
    int target = 73;
    
    // perform linear search and print result
    int lin_idx = linear_search(arr, len, target);
    if(lin_idx == -1){
        printf("Element %d not found using linear search\n", target);
    }
    else{
        printf("Element %d found at index %d using linear search\n", target, lin_idx);
    }
    
    // perform binary search and print result
    int bin_idx = binary_search(arr, len, target);
    if(bin_idx == -1){
        printf("Element %d not found using binary search\n", target);
    }
    else{
        printf("Element %d found at index %d using binary search\n", target, bin_idx);
    }
    
    return 0;
}