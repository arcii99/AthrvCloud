//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* str1 = (char*)malloc(sizeof(char)*10);   // Allocate memory for a string
    printf("Enter a string: ");
    scanf("%s", str1);   // Read input string
    printf("You entered: %s\n", str1);   // Print the input string
    free(str1);   // Free memory allocated for the string

    int* arr1 = (int*)calloc(5, sizeof(int));   // Allocate memory for an array and set it to all zeros
    int i;
    printf("Enter 5 numbers: ");
    for(i=0;i<5;i++)
    {
        scanf("%d", &arr1[i]);   // Read input numbers
    }
    printf("You entered: ");
    for(i=0;i<5;i++)
    {
        printf("%d ", arr1[i]);   // Print the input array
    }
    printf("\n");
    free(arr1);   // Free memory allocated for the array

    int* ptr1 = (int*)malloc(sizeof(int));   // Allocate memory for a pointer
    int* ptr2 = (int*)malloc(sizeof(int));   // Allocate memory for another pointer
    *ptr1 = 10;   // Set the value of pointer 1 to 10
    *ptr2 = *ptr1;   // Set the value of pointer 2 to the value of pointer 1
    printf("Pointer 1 points to value: %d\n", *ptr1);   // Print the value of pointer 1
    printf("Pointer 2 points to value: %d\n", *ptr2);   // Print the value of pointer 2
    free(ptr1);   // Free memory allocated for pointer 1
    free(ptr2);   // Free memory allocated for pointer 2

    return 0;
}