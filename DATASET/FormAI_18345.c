//FormAI DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
  // Define a string
  char str1[100] = "Hello, World!";
  printf("Original string: %s\n", str1);

  // Find the length of the string
  int len = strlen(str1);
  printf("Length of string: %d\n", len);

  // Convert string to uppercase
  for (int i = 0; str1[i]; i++) {
    str1[i] = toupper(str1[i]);
  }
  printf("Uppercase string: %s\n", str1);

  // Replace a character in the string
  char to_replace = 'o';
  char replacement = 'x';
  for (int i = 0; str1[i]; i++) {
    if (str1[i] == to_replace) {
      str1[i] = replacement;
    }
  }
  printf("Replaced string: %s\n", str1);

  // Compare two strings
  char str2[100] = "Hello, World!";
  if (strcmp(str1, str2) == 0) {
    printf("Strings are equal\n");
  } else {
    printf("Strings are not equal\n");
  }

  // Concatenate two strings
  char str3[100] = "Goodbye, ";
  strcat(str3, str2);
  printf("Concatenated string: %s\n", str3);

  return 0;
}