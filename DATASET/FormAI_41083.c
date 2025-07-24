//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

int custom_search(int arr[], int size, int target){
    int low=0, high=size-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 13;
    int result = custom_search(arr, size, target);
    if(result == -1){
        printf("Element %d not found!\n", target);
    }
    else{
        printf("Element %d found at index %d.\n", target, result);
    }
    return 0;
}