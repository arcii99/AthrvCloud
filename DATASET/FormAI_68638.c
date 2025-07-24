//FormAI DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

/* Configurable values */
#define MAX_ARRAY_SIZE 100 // Maximum size of array
#define SEARCH_NUM 65 // Number to be searched in the array

/* Function to perform the searching */
int search(int arr[], int n, int search_num)
{
   int i;
   for (i = 0; i < n; i++)
   {
       if (arr[i] == search_num) // If number found
           return i; // Return the index of the number
   }
   return -1; // If number not found, return -1
}

int main()
{
   int arr[MAX_ARRAY_SIZE], n, i, search_index;
   
   /* Taking inputs from user */
   printf("Enter the size of array (maximum %d): ", MAX_ARRAY_SIZE);
   scanf("%d", &n);

   // Generating random numbers for array
   srand(time(NULL)); // Initializing random seed
   for (i = 0; i < n; i++)
   {
       arr[i] = rand() % 100; // Generating random numbers
       printf("%d ", arr[i]); // Printing the numbers
   }
   
   /* Calling the search function */
   search_index = search(arr, n, SEARCH_NUM);

   /* Printing the result */
   if (search_index == -1)
      printf("\n%d not found in array!", SEARCH_NUM);
   else
      printf("\n%d found at index %d in array!", SEARCH_NUM, search_index);

   return 0;
}