//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n*sizeof(int));

    // Check if memory has been successfully allocated
    if(ptr == NULL){
        printf("Memory allocation unsuccessful.\n");
        exit(0);
    }
    else{
        printf("Memory allocation successful.\n");
    }

    // Initialize elements of the array
    for(int i=0;i<n;i++){
        ptr[i] = i+1;
    }

    // Display the elements of the array
    printf("Elements of the array are: ");
    for(int i=0;i<n;i++){
        printf("%d ",ptr[i]);
    }

    // Deallocate the allocated memory using free()
    free(ptr);

    // Check if memory has been successfully deallocated
    if(ptr == NULL){
        printf("\nMemory deallocation successful.\n");
    }
    else{
        printf("\nMemory deallocation unsuccessful.\n");
        exit(0);
    }
    return 0;
}