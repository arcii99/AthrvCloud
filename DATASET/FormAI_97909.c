//FormAI DATASET v1.0 Category: Random ; Style: bold
/* 
  **Bold C Random Example Program**
  Author: [Your Name Here]
  Date Created: [Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, n;
  int min = 1;
  int max = 100;
  srand(time(0)); // Seed the random number generator
  
  // Display a welcome message to the user
  printf("**Bold C Random Example Program**\n");
  printf("================================\n\n");
  printf("Welcome to the C Random Example Program!\n\n");
  
  // Ask the user how many random numbers they want to generate
  printf("How many random numbers do you want to generate? ");
  scanf("%d", &n);
  
  // Generate and display the random numbers
  printf("\nHere are your %d random numbers between %d and %d:\n\n", n, min, max);
  for (i = 0; i < n; i++) {
    printf("%d\n", (rand() % (max - min + 1)) + min);
  }
  
  // Display a closing message to the user
  printf("\nThank you for using the C Random Example Program!\n");
  printf("===============================================\n");
  
  return 0;
}