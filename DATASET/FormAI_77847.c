//FormAI DATASET v1.0 Category: Data mining ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

//Function to print the array
void printArray(int* arr, int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    //Declaring and initializing the array
    int arr[20] = {3,5,7,8,4,6,2,1,9,11,23,12,54,67,32,56,87,43,23,34};
    int len = sizeof(arr)/sizeof(int);

    //Printing the unsorted array
    printf("Unsorted Array: ");
    printArray(arr,len);
  
    //Performing Selection Sort
    for(int i=0;i<len;i++){
        int minIndex = i;
        for(int j=i+1;j<len;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    //Printing the sorted array
    printf("Sorted Array: ");
    printArray(arr,len);

    return 0;
}