//FormAI DATASET v1.0 Category: Pattern printing ; Style: high level of detail
#include <stdio.h>

int main() {
   int n = 7; // Change the value of n to adjust the size of the pattern
   
   // First half of the pattern
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n-i; j++) {
         printf(" "); // Print spaces
      }
      for (int j = 1; j <= i; j++) {
         printf("%d", j); // Print ascending numbers
      }
      for (int j = i-1; j >= 1; j--) {
         printf("%d", j); // Print descending numbers
      }
      printf("\n"); // Move to the next line
   }
   
   // Second half of the pattern
   for (int i = n-1; i >= 1; i--) {
      for (int j = 1; j <= n-i; j++) {
         printf(" "); // Print spaces
      }
      for (int j = 1; j <= i; j++) {
         printf("%d", j); // Print ascending numbers
      }
      for (int j = i-1; j >= 1; j--) {
         printf("%d", j); // Print descending numbers
      }
      printf("\n"); // Move to the next line
   }
   
   return 0;
}