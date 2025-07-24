//FormAI DATASET v1.0 Category: Sorting ; Style: automated
#include<stdio.h>

void printArray(int arr[], int size){
    int i;
    for (i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size){
    int i,j,temp;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionSort(int arr[], int size){
    int i,j,key;
    for(i=1;i<size;i++){
        key=arr[i];
        j=i-1;
         while(j>=0&&arr[j]>key){
             arr[j+1]=arr[j];
             j=j-1;
         }
         arr[j+1]=key;
    }
}

void selectionSort(int arr[], int size){
    int i,j,minIndex,temp;
    for(i=0;i<size-1;i++){
        minIndex=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        temp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
}

int main(){
    int arr[]={12,35,87,26,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting: ");
    printArray(arr,size);
    
    printf("Array after bubble sort: ");
    bubbleSort(arr,size);
    printArray(arr,size);
    
    printf("Array after insertion sort: ");
    insertionSort(arr,size);
    printArray(arr,size);
    
    printf("Array after selection sort: ");
    selectionSort(arr,size);
    printArray(arr,size);
    return 0;
}