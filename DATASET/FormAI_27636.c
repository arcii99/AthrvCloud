//FormAI DATASET v1.0 Category: Memory management ; Style: bold
#include<stdio.h>

int main(){
    // Allocate memory space for integer pointers
    int *p1 = (int*) malloc(sizeof(int));
    int *p2 = (int*) malloc(sizeof(int));
    int *sum = (int*) malloc(sizeof(int));

    // Check if memory allocation is successful or not
    if(p1 == NULL || p2 == NULL || sum == NULL){
        printf("Memory allocation failed!");
        return 0;
    }

    // Take inputs
    printf("Enter first integer: ");
    scanf("%d", p1);
    printf("Enter second integer: ");
    scanf("%d", p2);

    // Calculate sum
    *sum = *p1 + *p2;

    // Print the sum
    printf("Sum of %d and %d is %d", *p1, *p2, *sum);

    // Deallocate memory space
    free(p1);
    free(p2);
    free(sum);

    return 0;
}