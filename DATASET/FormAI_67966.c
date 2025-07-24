//FormAI DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* ptr;
   int num_elements;
   int sum = 0;

   printf("Enter the number of elements:\n");
   scanf("%d", &num_elements);

   // Allocate memory dynamically using malloc()
   ptr = (int*) malloc(num_elements * sizeof(int));

   if (ptr == NULL) {
        printf("Allocation failed! Exiting the program\n");

        // Return non-zero status to indicate failure
        return 1;
   }

   printf("Enter elements:\n");

   // Get user input and calculate sum
   for (int i = 0; i < num_elements; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
   }

   printf("The sum of the elements is: %d\n", sum);

   // Free the dynamically allocated memory using free()
   free(ptr);

   return 0;
}