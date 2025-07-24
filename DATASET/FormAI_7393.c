//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  char fileName[] = "example.txt";
  char message[] = "This is an example file.";

  // Create and write to file
  file = fopen(fileName, "w");
  if(file == NULL) {
    printf("Error: Could not create file.\n");
    exit(1);
  }
  fprintf(file, "%s", message);
  fclose(file);

  // Read from file
  char buffer[100];
  file = fopen(fileName, "r");
  if(file == NULL) {
    printf("Error: Could not open file.\n");
    exit(1);
  }
  fgets(buffer, 100, file);
  printf("File contents: %s", buffer);
  fclose(file);

  return 0;
}