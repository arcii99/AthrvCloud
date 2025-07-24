//FormAI DATASET v1.0 Category: Searching algorithm ; Style: secure
#include<stdio.h>
#include<stdlib.h>

int secureBinarySearch(int* arr, int low, int high, int value){
    //Function to implement Binary Search in a secure manner

    if(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == value){
            return mid; //Value found at mid position
        }
        else if(arr[mid] < value){
            return secureBinarySearch(arr, mid + 1, high, value); //Search in right half
        }
        else{
            return secureBinarySearch(arr, low, mid - 1, value); //Search in left half
        }
    }
    return -1; //Value not found
}

int main(){
    int n, value, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array in ascending order:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the value to search: ");
    scanf("%d", &value);
    result = secureBinarySearch(arr, 0, n - 1, value);
    if(result == -1){
        printf("Value not found in the array.\n");
    }
    else{
        printf("Value found at index %d\n", result);
    }
    free(arr);
    return 0;
}