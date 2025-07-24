//FormAI DATASET v1.0 Category: Memory management ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

void printArray(int* arr, int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void allocateMemory(int** arr, int n) {
    if(n<=0) {
        return;
    }
    *arr = (int*)malloc(n*sizeof(int));
    allocateMemory(arr+1,n-1);
}

void freeMemory(int* arr, int n) {
    if(n<=0) {
        return;
    }
    free(arr);
    freeMemory(arr+1,n-1);
}

int main() {
    int n=5;
    int* arr=NULL;
    allocateMemory(&arr,n);
    if(arr==NULL) {
        printf("Memory allocation failed!");
        return 0;
    }
    for(int i=0;i<n;i++) {
        arr[i]=i+1;
    }
    printf("Array: ");
    printArray(arr,n);
    freeMemory(arr,n);
    arr=NULL;
    printf("Memory freed successfully.\n");
    return 0;
}