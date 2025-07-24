//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000];
  char output[1000];
  char temp[1000];

  printf("Enter a string of words:\n");
  fgets(input, 1000, stdin);

  int len = strlen(input);
  int index = 0;
  int wordCount = 0;
  int charCount = 0;

  for (int i = 0; i <= len; i++) {
    if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '\0') {
      wordCount++;
      temp[index] = '\0';
      index = 0;
      charCount += strlen(temp);

      if (strcmp(temp, "the") == 0) {
        strcat(output, "THE ");
      } else if (strcmp(temp, "and") == 0) {
        strcat(output, "& ");
      } else {
        strcat(output, temp);
        strcat(output, " ");
      }
    } else {
      temp[index] = input[i];
      index++;
    }
  }

  printf("Original Input:\n%s\n", input);
  printf("\nProcessed Output:\n%s\n", output);

  printf("\nNumber of Words: %d", wordCount);
  printf("\nNumber of Characters (excluding white spaces): %d", charCount);

  return 0;
}