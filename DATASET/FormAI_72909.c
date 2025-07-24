//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>

// A function to perform linear search on an integer array
// Returns the index of the element if found, otherwise returns -1
int linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

// A function to perform binary search on an integer array
// Returns the index of the element if found, otherwise returns -1
int binarySearch(int arr[], int l, int r, int key){
    if(r >= l){
        int mid = l + (r-l)/2;
        
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            return binarySearch(arr, l, mid-1, key);
        }
        else{
            return binarySearch(arr, mid+1, r, key);
        }
    }
    return -1;
}

int main(){
    int arr[] = {45, 12, 76, 34, 89, 23, 67};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 34;
    
    int linearIndex = linearSearch(arr, n, key);
    int binaryIndex = binarySearch(arr, 0, n-1, key);
    
    printf("Linear Search Result: ");
    if(linearIndex != -1)
        printf("%d found at index %d", key, linearIndex);
    else
        printf("%d not found", key);
    
    printf("\nBinary Search Result: ");
    if(binaryIndex != -1)
        printf("%d found at index %d", key, binaryIndex);
    else
        printf("%d not found", key);
    
    return 0;
}