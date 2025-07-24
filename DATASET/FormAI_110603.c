//FormAI DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include<stdio.h>

int search(int arr[], int size, int value){
    int i; 
    for(i=0;i<size;i++){ 
        if(value == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int value = 8;
    int index = search(arr, size, value);
    if(index != -1){
        printf("The element %d was found at index %d ", value, index);
    }else{
        printf("The element %d was not found in the array", value);
    }
    return 0;
}