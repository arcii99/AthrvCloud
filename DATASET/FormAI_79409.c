//FormAI DATASET v1.0 Category: Log analysis ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the hilarious C Log analysis program!\n");
  printf("We will analyze every single character in your C log file and extract the most important data...\n\n");

  FILE *fptr;
  int c;
  int bracket_counter = 0;
  int line_counter = 0;
  int printf_counter = 0;
  int bug_counter = 0;
  char last_char = ' ';

  fptr = fopen("my_c_program.log", "r");

  if (fptr == NULL) {
    printf("Oops, we could not open the file. Maybe check if it exists?\n");
    return 1;
  }

  while ((c = fgetc(fptr)) != EOF) {
    if (c == '{') {
      bracket_counter++;
    } else if (c == '}') {
      bracket_counter--;
      if (last_char == ';') {
        printf("Uh oh, you forgot to remove a semicolon before this closing bracket. You might have a bug!\n");
        bug_counter++;
      }
    } else if (c == '\n') {
      line_counter++;
      if (last_char == 'f' && printf_counter == 0) {
        printf("Congratulations! You just wrote your first printf statement on line %d!\n", line_counter);
        printf_counter++;
      }
    }
    last_char = c;
  }

  printf("\nAnalysis complete! Here are the results:\n");
  printf("Total lines in your C file: %d\n", line_counter);
  printf("Total { brackets in your C file: %d\n", bracket_counter);
  printf("Total printf statements in your C file: %d\n", printf_counter);
  printf("Total bugs detected in your C file: %d\n", bug_counter);
  printf("\nThank you for using our C Log analysis program! Don't forget to keep your code funny along the way :)\n");

  fclose(fptr);
  return 0;
}