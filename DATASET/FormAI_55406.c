//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>

void move(int count, char tower1, char tower2, char tower3);

int main() {
   int numDisks = 0;

   // Prompt user for the number of disks
   printf("Enter the number of disks: ");
   scanf("%d", &numDisks);

   // Ensure that the input value is valid
   if (numDisks <= 0) {
      printf("Invalid input. Please enter a positive integer.\n");
      return 0;
   }
   
   // Print the initial setup of the towers
   printf("Initial setup:\n");
   printf("Tower 1 (source): ");
   for (int i = numDisks; i >= 1; i--) {
      printf("%d ", i);
   }
   printf("\n");
   printf("Tower 2 (auxiliary): \n");
   printf("Tower 3 (destination): \n");
   
   // Call the move function to solve the problem
   move(numDisks, '1', '2', '3');
   
   return 0;
}

void move(int count, char tower1, char tower2, char tower3) {
   if (count > 0) {
      // Move count-1 disks from tower 1 to tower 2 using tower 3
      move(count-1, tower1, tower3, tower2);

      // Move the largest disk from tower 1 to tower 3
      printf("Moved disk %d from tower %c to tower %c.\n", count, tower1, tower3);

      // Move the remaining disks from tower 2 to tower 3 using tower 1
      move(count-1, tower2, tower1, tower3);
   }
}