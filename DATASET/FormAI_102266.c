//FormAI DATASET v1.0 Category: Memory management ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    // Allocate memory dynamically
    int *arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL){
        printf("Memory could not be allocated!\n");
        exit(0);
    }

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    // Display the elements
    printf("\nElements in the array: ");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    // Deallocate the memory
    free(arr);

    return 0;
}