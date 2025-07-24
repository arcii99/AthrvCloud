//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size){
    int i,j;
    int* bucket;
    int max = arr[0];
    for(i=1;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    bucket = (int*) calloc(max+1,sizeof(int));
    for(i=0;i<size;i++){
        bucket[arr[i]]++;
    }
    for(i=0,j=0;i<=max;i++){
        while(bucket[i]>0){
            arr[j++]=i;
            bucket[i]--;
        }
    }
    free(bucket);
}

int main(){
    printf("Welcome to the C Bucket Sort Implementation!!\n");
    printf("I hope you brought your buckets and spades...hehehe!\n");
    int arr[] = {45, 23, 89, 67, 34, 55, 20, 11, 9, 88, 74};
    printf("Unsorted array: ");
    printArray(arr,11);
    bucketSort(arr,11);
    printf("Sorted array: ");
    printArray(arr,11);
    printf("Congratulations! You are now the proud owner of a sorted array.\n");
    printf("I hope that your buckets and spades are now safely tucked away!!\n");
    return 0;
}