//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int search(int arr[], int n, int key){
    int i;
    for(i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int i, n, key, index;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the key element to search:\n");
    scanf("%d", &key);

    index = search(arr, n, key);

    if(index == -1){
        printf("%d not found in the array.\n", key);
    }
    else{
        printf("%d found at index %d in the array.\n", key, index);
    }
    return 0;
}