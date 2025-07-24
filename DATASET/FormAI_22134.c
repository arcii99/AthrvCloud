//FormAI DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>

// Interoperable searching function that searches for a given value in an array
int searchArray(int arr[], int n, int val){
    for (int i=0; i<n; i++){
        if (arr[i] == val){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {9, 3, 5, 2, 8, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = 5;
    int index = searchArray(arr, n, val);
    if (index == -1){
        printf("%d not found in array.\n", val);
    }
    else {
        printf("%d found at index %d.\n", val, index);
    }
    return 0;
}