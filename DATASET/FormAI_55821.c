//FormAI DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr1 = (int*) malloc(sizeof(int)); //Allocate memory block and assign its reference to ptr1
    printf("The address of ptr1 is: %p\n", ptr1); //Print ptr1 memory address
    
    //Fill the memory block with some integer values using pointer notation
    *(ptr1) = 10;
    *(ptr1+1) = 20;
    *(ptr1+2) = 30;
    *(ptr1+3) = 40;

    printf("Printing the values stored in the memory block:\n");

    //Loop over the memory block and print its content using pointer notation again
    for (int i = 0; i < 4; i++) {
        printf("%d\n", *(ptr1+i));
    }

    //Release the memory block assigned to ptr1
    free(ptr1);
    
    //Allocating memory block to ptr2 using calloc
    int* ptr2 = (int*) calloc(5, sizeof(int));
    printf("\nThe address of ptr2 is: %p\n", ptr2); //Print ptr1 memory address

    printf("Printing the values before using realloc:\n");
    //Loop over the memory block and print its content using pointer notation again
    for (int i = 0; i < 5; i++) {
        printf("%d\n", *(ptr2+i));
    }

    //Increase the memory block allocated to ptr2 to store 10 integers
    ptr2 = (int*) realloc(ptr2, 10*sizeof(int));
    printf("\nThe new address of ptr2 after using realloc is: %p\n", ptr2); //Print new memory address

    //Update the memory block content using pointer notation
    *(ptr2+5) = 50;
    *(ptr2+6) = 60;
    *(ptr2+7) = 70;
    *(ptr2+8) = 80;
    *(ptr2+9) = 90;

    printf("Printing the values after using realloc:\n");
    //Loop over the memory block and print its content using pointer notation again
    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(ptr2+i));
    }

    //Release the memory block assigned to ptr2
    free(ptr2);

    return 0;
}