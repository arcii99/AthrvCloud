//FormAI DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>

int search(int arr[], int n, int key){
    int i;
    for(i = 0; i < n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = { 4, 6, 8, 1, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;
    int result = search(arr, n, key);
    if(result == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index %d\n", result);
    }
    return 0;
}