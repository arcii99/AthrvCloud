//FormAI DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>

int main() {
  FILE *file_ptr;
  char file_name[50], file_content[500], new_content[50];
  int length;

  printf("Enter name of file to open:\n");
  scanf("%s", file_name);

  // Open file in write mode
  file_ptr = fopen(file_name, "w");

  if (file_ptr != NULL) {
    printf("\nEnter content to write in the file:\n");
    scanf(" %[^\n]s", file_content); // read string with whitespaces

    // Write to file
    fprintf(file_ptr, "%s", file_content);

    // Close file
    fclose(file_ptr);

    printf("\nFile saved successfully.\n\n");

    // Open file to read
    file_ptr = fopen(file_name, "r");

    if (file_ptr != NULL) {
      // Read file content
      fseek(file_ptr, 0, SEEK_END);
      length = ftell(file_ptr);
      fseek(file_ptr, 0, SEEK_SET);
      fread(new_content, length, 1, file_ptr);

      // Display file content
      printf("File content:\n%s\n\n", new_content);

      // Close file
      fclose(file_ptr);
    } else {
      printf("\nFailed to read file.\n\n");
    }
  } else {
    printf("\nFailed to save file.\n\n");
  }

  return 0;
}