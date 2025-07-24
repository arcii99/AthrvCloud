//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include<stdio.h>

int math_search(int arr[], int n, int key){
    int low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]<key){
            low = mid+1;
        }
        else if(arr[mid]>key){
            high = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 12;
    int index = math_search(arr, n, key);
    
    if(index == -1){
        printf("%d not found in the array", key);
    }
    else{
        printf("%d found at index %d in the array.", key, index);
    }
    return 0;
}