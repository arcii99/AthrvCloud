//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>

int main() {
  char str[100];
  printf("Enter a string: ");

  // Read user input
  fgets(str, 100, stdin);

  // Count number of words
  int num_words = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ' && str[i + 1] != ' ') {
      num_words++;
    }
  }

  // Reverse each word
  char rev_str[100];
  int start = 0;
  int end;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ' || str[i + 1] == '\0') {
      if (str[i + 1] == '\0') {
        end = i;
      } else {
        end = i - 1;
      }

      // Reverse word
      for (int j = end; j >= start; j--) {
        rev_str[end - j + start] = str[j];
      }
      rev_str[end - start + 1] = ' ';

      start = i + 1;
    }
  }

  // Print results
  printf("\nOriginal string: %s", str);
  printf("Number of words: %d\n", num_words + 1);
  printf("Reversed string: %s\n", rev_str);

  return 0;
}