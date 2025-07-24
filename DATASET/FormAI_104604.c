//FormAI DATASET v1.0 Category: Data recovery tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 // Size of buffer used to read from file

int main() {
  char file_name[100]; // User input for file name
  char recovery_name[100]; // User input for recovered file name
  char buffer[BUFFER_SIZE]; 
  FILE *original_file, *recovered_file;
  long file_size; 
  size_t bytes_read;

  printf("Enter the name of the file to be recovered: ");
  scanf("%s", file_name);

  original_file = fopen(file_name, "rb"); // Open original file in binary mode

  if (!original_file) {
    printf("Error: Could not open file %s", file_name);
    return 1;
  }

  fseek(original_file, 0, SEEK_END); // Move pointer to end of file
  file_size = ftell(original_file); // Get size of file
  fseek(original_file, 0, SEEK_SET); // Move pointer back to beginning of file

  printf("Enter the name of the recovered file: ");
  scanf("%s", recovery_name);

  recovered_file = fopen(recovery_name, "wb"); // Open recovered file in binary mode

  if (!recovered_file) {
    printf("Error: Could not create file %s", recovery_name);
    return 1;
  }

  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, original_file)) > 0) { // Read from original file into buffer
    fwrite(buffer, 1, bytes_read, recovered_file); // Write from buffer into recovered file
  }

  fclose(original_file);
  fclose(recovered_file);

  printf("Recovery successful!\n");
  return 0;
}