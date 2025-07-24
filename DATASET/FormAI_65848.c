//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include<stdio.h>  

int main()  
{  
    printf("Welcome to the exciting world of C Memory Management!\n\n");

    int size;

    printf("How many integers do you want to store in the array? Enter a positive integer: ");
    scanf("%d", &size);

    // Create an integer array of user specified size
    int *array = (int*) malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed! Exiting the program...\n");
        return 0;
    }

    printf("\nGreat! You have successfully allocated %d bytes of memory for the array.\n\n", size * sizeof(int));
    printf("Let's fill up the array with some numbers.\n");

    for (int i = 0; i < size; i++) {
        printf("Enter integer %d: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nAwesome! You have filled up the array with %d integers.\n\n", size);
    printf("Let's print out the array:\n");

    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i+1, array[i]);
    }

    printf("\nWonderful! You have successfully utilized the allocated memory space.\n");

    printf("\nNow, let's free up the memory space.\n");

    free(array);

    printf("\nCongratulations! You have freed up the allocated memory space.\n");

    return 0;  
}