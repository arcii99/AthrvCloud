//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
/* This is a unique searching algorithm that uses a combination of linear search and binary search
It has been named the "Hybrid Search"
It is designed to search through an array of integers for a user-defined key*/

#include <stdio.h>

void hybrid_search(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int linear_index;

    // First, we perform a linear search to find the approximate location of the key
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            printf("%d found at index %d", key, i);
            return;
        }

        if(arr[i] > key){
            linear_index = i-1;
            break;
        }
    }

    // If the key is not found, we perform a binary search on the remaining values
    printf("Performing binary search\n");
    while(start <= end){
        int mid = (start + end)/2;

        if(arr[mid] == key){
            printf("%d found at index %d", key, mid);
            return;
        }
        else if(arr[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    printf("%d not found in the array", key);
}

int main(){
    int arr[] = {1, 4, 7, 12, 14, 19, 22, 29};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 19;

    hybrid_search(arr, n, key);

    return 0;
}