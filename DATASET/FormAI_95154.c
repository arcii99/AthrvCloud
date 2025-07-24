//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

  FILE *file_ptr;
  char filename[256], ch;
  int count = 0, in_word = 0;

  // Get filename from the command line argument
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  strcpy(filename, argv[1]);

  // Open the file
  file_ptr = fopen(filename, "r");
  if (file_ptr == NULL) {
    printf("Error: cannot open file %s\n", filename);
    return 1;
  }

  // Count the number of words in the file
  while ((ch = fgetc(file_ptr)) != EOF) {
    if (isalnum(ch)) {
      if (!in_word) {
        count++;
        in_word = 1;
      }
    } else {
      in_word = 0;
    }
  }

  // Display the result in a cyberpunk-themed interface
  printf("\n|--------------------------|\n");
  printf("| Total words in \"%s\" file: %d |\n", filename, count);
  printf("|--------------------------|\n\n");

  // Close the file and exit
  fclose(file_ptr);
  return 0;
}