//FormAI DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>

int binarySearch(int arr[], int n, int x){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == x)      //if x is present at mid
            return mid;
        else if(arr[mid] < x)  //if x is present in right side
            low = mid + 1;
        else                   //if x is present in left side
            high = mid - 1;
    }
    return -1; //if x is not present in array
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    printf("Input Array:  ");
    printArray(arr, n);
    printf("Element %d is at index %d\n", x, binarySearch(arr, n, x));
    return 0;
}