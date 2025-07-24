//FormAI DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Defining the search function
int search(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == target){
            return mid;
        }
        else if (arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int index = search(arr, size, target);
    if (index != -1){
        printf("Target found at index %d\n", index);
    }
    else{
        printf("Target not found\n");
    }
    return 0;
}