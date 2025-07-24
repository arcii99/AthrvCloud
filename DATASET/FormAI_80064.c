//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *arr; //declaring integer variables 'n' and a pointer variable 'arr'
    printf("Enter the size of the array: "); //user input for the size of the array
    scanf("%d", &n); // reading the size of the array
    arr = (int*)malloc(n*sizeof(int)); // dynamic memory allocation of size 'n' for integer array 'arr'
    
    if(arr==NULL){ //if memory not allocated
        printf("Memory allocation failed!");
        exit(0);
    }
    else{ //if memory allocated
        printf("Memory allocated successfully!\n");
    }

    // Taking input from user
    printf("Enter %d elements in the array: ", n); 
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]); //reading element at position 'i'
    }
    
    //displaying elements of an array
    printf("\nThe elements in the array are: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]); //Accessing element at position 'i' and printing it
    }
    printf("\n");

    //deallocating the memory
    free(arr);
    printf("Memory freed successfully!\n");
    return 0;
}