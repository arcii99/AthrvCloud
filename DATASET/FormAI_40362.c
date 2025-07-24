//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include<stdio.h>
#include<stdlib.h>

int main()
{
	// The program will demonstrate error handling in C language
	// First, we will allocate memory dynamically using malloc
	// If the memory allocation succeeds, then we will print the values stored in the array
	// Otherwise, we will display an error message and exit the program
	
	int* numbers; // Pointer to int
	int size; // Size of the array
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	
	// Allocate memory dynamically
	numbers = (int*)malloc(size * sizeof(int)); // Using malloc to allocate memory
	
	// Check whether the allocation was successful or not
	if(numbers == NULL) // If memory allocation fails, print the error message and exit the program
	{
		printf("\nMemory allocation failed, exiting the program.\n");
		exit(0); // Exiting the program
	}
	
	// If memory allocation was successful, we can proceed with the program
	printf("\nEnter %d values into the array:\n", size);
	
	// Loop through the array and take input from the user
	for(int i = 0; i < size; i++)
	{
		printf("Element %d: ", i+1);
		scanf("%d", &numbers[i]);
	}
	
	// Display the values stored in the array
	printf("\nValues stored in the array are:\n");
	for(int i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
	
	// Free the allocated memory
	free(numbers);
	
	return 0; // Exiting the program successfully
}