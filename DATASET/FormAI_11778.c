//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Memory Management Funhouse!\n\n");

  int* myNumber = (int*) malloc(sizeof(int)); // We'll allocate an integer's worth of memory
  *myNumber = 42; // Set the value at the address of our dynamically allocated memory to 42

  printf("myNumber currently points to the value: %d\n", *myNumber);
  free(myNumber); // Free the allocated memory to avoid a memory leak

  char* myString = (char*) malloc(25 * sizeof(char)); // Allocate space for a 25 character string
  strncpy(myString, "I am a string, hear me roar", 25); // Set the string at the address of our memory

  printf("myString currently points to the value: %s\n\n", myString);
  free(myString); // Free the allocated memory again to avoid a stringy situation

  printf("Thanks for visiting the Memory Management Funhouse!\n");
  return 0;
}