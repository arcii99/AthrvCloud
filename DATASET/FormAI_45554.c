//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h> //header file for standard input/output functions
#include <stdlib.h> //header file for malloc() and free() functions

void printArray(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int *arr=NULL; //creating a pointer to integer and initialized with NULL
    int n=0; //size of array
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("\n");
    arr=(int*)malloc(n*sizeof(int)); //allocating memory dynamically for integer array
    if(arr==NULL){ //checking if memory is allocated or not
        printf("Error allocating memory");
        return 0;
    }else{
        printf("Memory allocated successfully\n");
        printf("-------------------------\n");
        printf("Enter array elements: \n");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        printf("\nArray elements: ");
        printArray(arr,n); //function call to print elements of array
        printf("\n");
        free(arr); //releasing the allocated memory
        printf("Memory freed successfully\n");
        return 0;
    }
}