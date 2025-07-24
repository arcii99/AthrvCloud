//FormAI DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  printf("Welcome to the Surrealist Memory Management System!\n\n");
  
  // Allocate memory for a random number of integers
  int* numbers = malloc(sizeof(int) * (rand() % 10 + 1));
  
  // Populate the array with random numbers
  for (int i = 0; i < sizeof(numbers)/sizeof(int); i++) {
    numbers[i] = rand() % 100;
  }
  
  // Print the array
  printf("The numbers are: ");
  for (int i = 0; i < sizeof(numbers)/sizeof(int); i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
  
  // Allocate memory for a random number of characters
  char* string = malloc(sizeof(char) * (rand() % 10 + 1));
  
  // Populate the string with random lowercase letters
  for (int i = 0; i < sizeof(string)/sizeof(char); i++) {
    string[i] = rand() % 26 + 97;
  }
  
  // Print the string
  printf("The string is: %s\n", string);
  
  // Free the memory
  free(numbers);
  free(string);
  
  printf("\nThank you for using the Surrealist Memory Management System.\n");
  
  return 0;
}