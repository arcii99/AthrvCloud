//FormAI DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include<stdio.h>

int search(int arr[], int search_key, int n){
    int left = 0;
    int right = n - 1;
    int mid;
    
    while(left <= right){
        mid = (left + right) / 2;
        if(arr[mid] == search_key){
            return mid;
        }
        else if(arr[mid] < search_key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n, arr[100], search_key, result, i;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter search key:\n");
    scanf("%d", &search_key);
    result = search(arr, search_key, n);
    if(result == -1){
        printf("Element not found!\n");
    }
    else{
        printf("Element found at index %d!\n", result);
    }
    return 0;
}