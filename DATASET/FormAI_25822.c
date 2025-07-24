//FormAI DATASET v1.0 Category: Searching algorithm ; Style: automated
#include<stdio.h>

int search(int *arr, int size, int element){
    int low = 0, high = size-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == element){
            return mid;
        }
        else if(arr[mid] > element){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(int);
    int element = 5;

    int result = search(arr, size, element);

    if(result == -1){
        printf("Element not found!\n");
    }
    else{
        printf("Element found at index %d\n", result);
    }
    return 0;
}