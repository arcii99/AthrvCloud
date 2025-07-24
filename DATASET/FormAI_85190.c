//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

int binary_search(int a[], int lo, int hi, int key){
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(key == a[mid]){
            return mid;
        }
        else if(key < a[mid]){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int key = 7;
    int index = binary_search(arr, 0, 9, key);
    if(index == -1){
        printf("Element not found.\n");
    }
    else{
        printf("Element found at index %d.\n", index);
    }
    return 0;
}