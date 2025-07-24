//FormAI DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include<stdio.h>

int search(int arr[], int n, int key){
    int i;
    for(i=0; i<n; i++){
        if(arr[i]==key)
            return i;
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 3;
    int result = search(arr, n, key);
    if(result==-1)
        printf("Key not found\n");
    else
        printf("Key found at index %d\n", result);
    return 0;
}