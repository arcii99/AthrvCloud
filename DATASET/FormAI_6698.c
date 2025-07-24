//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

int main() {
  // Allocate memory for a string of length 10
  char* str = (char*) malloc(10 * sizeof(char));

  // Check if allocation was successful
  if (str == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  // Initialize the string
  str[0] = 'H';
  str[1] = 'e';
  str[2] = 'l';
  str[3] = 'l';
  str[4] = 'o';
  str[5] = ' ';
  str[6] = 'W';
  str[7] = 'o';
  str[8] = 'r';
  str[9] = 'l';
  str[10] = 'd'; // Accessing beyond allocated memory

  // Print the string
  printf("%s\n", str);

  // Free the memory
  free(str);

  // Trying to access freed memory
  printf("%s\n", str);

  return 0;
}