//FormAI DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>

int main() {
  // Creating a file pointer
  FILE *file;
  
  // Opening the file in write mode
  file = fopen("example.txt", "w");
  
  // Writing to the file
  fprintf(file, "Hello, World!");
  
  // Closing the file
  fclose(file);
  
  // Opening the file in read mode
  file = fopen("example.txt", "r");
  
  // Reading from the file
  char c = fgetc(file);
  while (c != EOF) {
    printf("%c", c);
    c = fgetc(file);
  }
  
  // Closing the file
  fclose(file);
  
  return 0;
}