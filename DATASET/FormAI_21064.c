//FormAI DATASET v1.0 Category: Searching algorithm ; Style: careful
#include<stdio.h>

int binarySearch(int arr[], int l, int r, int x){

    if(r >= l){

        int mid = l + (r-l)/2;

        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] > x){
            return binarySearch(arr, l, mid-1, x);
        }

        return binarySearch(arr, mid+1, r, x);
    }

    return -1;
}

int main(){

    int arr[] = {2, 5, 7, 9, 12, 16, 18};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Enter the number to search: ");
    int x;
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n-1, x);

    if(result == -1){
        printf("Number not found in array.\n");
    }
    else{
        printf("Number found at index %d.\n", result);
    }

    return 0;
}