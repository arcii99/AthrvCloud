//FormAI DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>

int main() {
  // Opening a file for writing
  FILE *file = fopen("test.txt", "w");
  
  // Checking if file was opened successfully or not
  if(file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
  
  // Writing data to file
  const char *data = "Hello, world!";
  fprintf(file, "%s\n", data);
  
  // Closing the file
  fclose(file);

  // Opening a file for reading
  file = fopen("test.txt", "r");

  // Checking if file was opened successfully or not
  if(file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
  
  // Reading data from file
  char buffer[100];
  fgets(buffer, sizeof(buffer), file);
  printf("Data read from file: %s\n", buffer);
  
  // Closing the file
  fclose(file);

  return 0;
}