//FormAI DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

// function to search for element 'key' in array 'arr' of size 'n'
int search(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key)
            return i; //return index of searched element in array
    }
    return -1; //element not found
}

int main(){
    int n; //size of array
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    
    //reading array elements from user
    printf("Enter array elements: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    int key; //element to be searched for
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    int index = search(arr, n, key);
    if(index == -1){
        printf("Element not found!\n");
    }
    else{
        printf("Element found at index %d\n", index);
    }
    
    return 0;
}