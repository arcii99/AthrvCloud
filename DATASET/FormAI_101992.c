//FormAI DATASET v1.0 Category: Scientific ; Style: inquisitive
#include<stdio.h>

int main()
{
    /*
    This is a program to demonstrate the use of pointer arithmetic in C.
    We will create an integer array and will use pointer arithmetic to traverse through it.
    */

    int arr[5] = {1, 2, 3, 4, 5}; //creating an integer array with 5 elements
    int *ptr; //declaring an integer pointer

    ptr = arr; //initializing the pointer with the base address of the array

    printf("Printing the elements of the array using pointer arithmetic.\n");

    //traversing through the array using pointer arithmetic
    for(int i=0; i<5; i++)
    {
        printf("%d ", *ptr); //printing the value pointed by the pointer
        ptr++; //incrementing the pointer to point to next element
    }

    //Now, let's perform some arithmetic operations on the pointer
    ptr = arr; //re-initializing the pointer with the base address of the array

    printf("\nPrinting the same elements of the array after performing some pointer arithmetic.\n");

    //traversing through the array using pointer arithmetic
    for(int i=0; i<5; i++)
    {
        printf("%d ", *(ptr+i)); //printing the value pointed by the pointer after adding i to it
    }

    return 0; //indicating successful execution of the program
}