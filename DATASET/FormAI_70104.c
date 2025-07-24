//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

/* Mathematical Memory Management
* This program simulates a mathematical function using specific requirements for memory allocation
* It will allocate an array of integers, dynamically based on user input.
* The array will be filled with integers based on a mathematical function.
* Finally, it will perform memory cleanup by freeing the allocated space.
*/

int main()
{
  int n, i;
  printf("Enter the number of integers to calculate\n");
  scanf("%d", &n);

  // Request memory allocation for the array
  int *myArray = (int*)malloc(n*sizeof(int));

  // Check if memory is available
  if (myArray == NULL)
  {
     printf("Error! memory not allocated.");
     exit(0);
  }

  // Fill the array with values calculated with a mathematical function
  for (i = 0; i < n; i++)
  {
     myArray[i] = (i+1)*(i+3);
  }

  // Display the contents of the array
  printf("The contents of the array are:\n");
  for (i = 0; i < n; i++)
  {
     printf("%d\n", myArray[i]);
  }

  // Free the dynamically allocated memory to avoid memory leaks
  free(myArray);

  printf("Memory cleanup complete!\n");
  
  return 0;
}