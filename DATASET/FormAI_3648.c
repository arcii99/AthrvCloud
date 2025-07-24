//FormAI DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int linear_search(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int low, int high, int key){
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 16;

    printf("Array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    printf("\n\nLinear Search:\n\n");
    int linear_search_result=linear_search(arr,size,key);
    if(linear_search_result==-1){
        printf("\n%d not found.\n",key);
    }else{
        printf("\n%d found at index %d.\n",key,linear_search_result);
    }

    printf("\nBinary Search:\n\n");
    int binary_search_result=binary_search(arr,0,size-1,key);
    if(binary_search_result==-1){
        printf("\n%d not found.\n",key);
    }else{
        printf("\n%d found at index %d.\n",key,binary_search_result);
    }

    return 0;
}