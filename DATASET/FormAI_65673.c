//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main(){
    int* ptr; // declare pointer to int
    int n, i;

    printf("Enter number of integers to be entered: ");
    scanf("%d",&n);

    ptr = (int*)malloc(n*sizeof(int)); // allocate memory block for n ints

    // check if memory allocation was successful
    if(ptr == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }

    // prompt user to enter integers
    printf("Enter %d integers: ", n);
    for(i = 0; i < n; i++){
        scanf("%d",(ptr+i));
    }

    // print integers entered by user
    printf("You entered: ");
    for(i = 0; i < n; i++){
        printf("%d ",*(ptr+i));
    }

    free(ptr); // free memory block

    return 0;
}