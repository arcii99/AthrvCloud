//FormAI DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>


int main() {

  /* Open a file for reading */
  FILE *file = fopen("input.txt", "r");

  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  /* Count the number of lines in the file */
  char line[100];
  int num_lines = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    num_lines++;
  }

  /* Print the number of lines */
  printf("Number of lines in the file: %d\n", num_lines);

  /* Close the file */
  fclose(file);

  /* Reopen the file for writing */
  file = fopen("output.txt", "w");

  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  /* Write a string to the file */
  char message[] = "Hello, world!";
  fprintf(file, message);

  /* Close the file */
  fclose(file);

  /* Reopen the file for reading */
  file = fopen("output.txt", "r");

  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  /* Read the contents of the file into a string */
  char output[100];
  fgets(output, sizeof(output), file);

  /* Print the string */
  printf("String read from file: %s", output);

  /* Close the file */
  fclose(file);

  /* Reverse the string */
  char reversed[strlen(output)];
  int i, j;
  for (i = strlen(output) - 1, j = 0; i >= 0; i--, j++) {
    reversed[j] = output[i];
  }
  reversed[j] = '\0';

  /* Print the reversed string */
  printf("Reversed string: %s\n", reversed);

  return 0;
}