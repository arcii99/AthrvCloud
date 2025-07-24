//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int matrix[5][5], i, j, sum=0;
  
  printf("Hi there! I am a matrix operations program! But before we get started, let's create a random 5x5 matrix!\n");
  printf("Here we go!\n");

  srand(time(NULL)); // Seed the random number generator

  // Fill the matrix with random numbers between -50 and 50
  for (i=0; i<5; i++) {
    printf("| "); // Just for aesthetics
    for (j=0; j<5; j++) {
      matrix[i][j] = (rand() % 101) - 50;
      printf("%2d ", matrix[i][j]); // Print the element
    }
    printf("|\n"); // Just for aesthetics
  }
  
  printf("Wow, that was fun! Now, let's find the sum of all the positive numbers in the matrix. Let me show you how it's done!\n");
  
  // Calculate the sum of all positive numbers in the matrix
  for (i=0; i<5; i++) {
    for (j=0; j<5; j++) {
      if (matrix[i][j] > 0) {
        sum += matrix[i][j]; // Add the positive number to the sum
      }
    }
  }
  
  printf("The sum of all the positive numbers in the matrix is %d. Neat, right?\n", sum);
  
  return 0; // Bye bye!
}