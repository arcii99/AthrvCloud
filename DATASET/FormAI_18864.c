//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>

int main() {
  printf("Welcome to my file handling example program!\n\n");

  // create a file
  FILE *file = fopen("my_file.txt", "w");

  if (file == NULL) {
    printf("Error creating file.");
    return 1;
  }

  printf("File created successfully!\n");

  // write to a file
  char message[] = "I am so grateful for this opportunity to learn and grow!";
  fprintf(file, "%s", message);

  printf("Message written to file successfully!\n");

  // close the file
  fclose(file);

  // read from a file
  file = fopen("my_file.txt", "r");

  if (file == NULL) {
    printf("Error opening file.");
    return 1;
  }

  printf("\nContents of file:\n");
  char character;
  while ((character = fgetc(file)) != EOF) {
    printf("%c", character);
  }

  // close the file
  fclose(file);

  printf("\n\nThank you for using my program! Have a great day!\n");

  return 0;
}