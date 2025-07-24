//FormAI DATASET v1.0 Category: Searching algorithm ; Style: automated
#include<stdio.h>

int binarySearch(int arr[], int l, int r, int x);

int main(){
    
    //initialize an array of integers
    int arr[] = {2, 6, 12, 15, 18, 20, 25, 31, 40, 55, 60, 65};
    
    //get the length of the array
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //number to search for
    int x = 25;
    
    //perform binary search on the array
    int result = binarySearch(arr, 0, n - 1, x);
    
    //print result
    if(result == -1){
        printf("Element not found in array.");
    }else{
        printf("Element found at index %d", result);
    }

    return 0;
}

int binarySearch(int arr[], int l, int r, int x){
    
    //loop till left index is less than or equal to right index
    while(l <= r){
        //get the mid index
        int mid = (l + r) / 2;
        
        //if the mid element is the number we are looking for, return the index
        if(arr[mid] == x){
            return mid;
        }
        
        //if the mid element is greater than the number we are looking for, search in the left half of the array
        if(arr[mid] > x){
            r = mid - 1;
        //if the mid element is less than the number we are looking for, search in the right half of the array
        }else{
            l = mid + 1;
        }
    }
    
    //element not found 
    return -1;
}