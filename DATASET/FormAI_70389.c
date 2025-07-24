//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x){
    if (right >= left){
        int mid = left + (right - left) / 2;
        if (arr[mid] == x){
            return mid;
        }
        if (arr[mid] > x){
            return binarySearch(arr, left, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, right, x);;
    }
    return -1;
}

int main(){
    int arr[100], n, i, x, result;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);
    printf("Enter the elements of the array in increasing order: \n");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be searched: ");
    scanf("%d", &x);
    result = binarySearch(arr, 0, n - 1, x);
    if (result == -1){
        printf("Element not found in the array.\n");
    }
    else{
        printf("Element found at index %d.\n", result);
    }
    return 0;
}