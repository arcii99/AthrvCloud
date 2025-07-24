//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    if(arr == NULL){
        printf("Memory allocation failed!");
        exit(1);
    }

    printf("\nEnter %d elements into the array: ", size);
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the array are: ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    free(arr);
    printf("\nMemory successfully freed.");

    return 0;
}