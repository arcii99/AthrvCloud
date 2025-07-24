//FormAI DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include<stdio.h>

int search(int arr[], int size, int key){
    // Iterate through array elements
    for(int i=0; i<size; i++){
      // Return index if element found
      if(arr[i]==key){
          return i;
      }
    }
    // Return -1 if element not found
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=5;
    // Call search function to find index of key in array
    int index=search(arr, size, key);
    // Check if key found or not
    if(index!=-1){
        printf("Element %d found at index %d \n", key, index);
    }
    else{
        printf("Element not found \n");
    }
    return 0;
}