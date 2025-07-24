//FormAI DATASET v1.0 Category: Scientific ; Style: sophisticated
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int num) {
   if (num <= 1) {
      return 1;
   } else {
      return num * factorial(num - 1);
   }
}

int main() {
   int n, result, i, j;

   printf("Enter a value for n: ");
   scanf("%d", &n);

   // Create an array to store the pascal's triangle
   int pascalTriangle[n][n];

   // Loop through each row in the triangle
   for (i = 0; i < n; i++) {
      
      // Print the appropriate number of spaces before each row
      for (j = 0; j < (n - i - 1); j++) {
         printf(" ");
      }

      // Loop through each column in the row
      for (j = 0; j <= i; j++) {
         
         // Calculate the result using the factorial function
         result = factorial(i) / (factorial(j) * factorial(i - j));
         
         // Store the result in the array
         pascalTriangle[i][j] = result;

         // Print the result with appropriate spacing
         printf("%d ", result);
      }

      // Print a new line after each row
      printf("\n");
   }

   // Print the Pascal's Triangle using the stored values in the array
   printf("\nThe Pascal's Triangle:\n");

   for (i = 0; i < n; i++) {
      for (j = 0; j <= i; j++) {
         printf("%d ", pascalTriangle[i][j]);
      }
      printf("\n");
   }

   return 0;
}