//FormAI DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int left, int right, int toFind){
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == toFind)
            return mid;
        
        if (arr[mid] < toFind)
            left = mid + 1;
        else 
            right = mid - 1;
    }
    
    return -1;
}

int main(){
    int n, toFind;
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements of array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
     
    printf("Enter element to search: ");
    scanf("%d", &toFind);
    
    int result = binarySearch(arr, 0, n - 1, toFind);
    
    if(result == -1)
        printf("Element not present in array");
    else
        printf("Element found at index %d", result);
    
    return 0;
}