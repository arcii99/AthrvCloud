//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[1000];
  char sanitizedStr[1000];
  int i, j, len;
  printf("Enter the string to be sanitized: ");
  fgets(str, sizeof(str), stdin);
  len = strlen(str);

  // Removing leading and trailing white space
  while (isspace(str[0])) {
    strcpy(str, str + 1);
    len--;
  }
  while (isspace(str[len - 1])) {
    str[len - 1] = '\0';
    len--;
  }

  j = 0;
  // Sanitizing the input; Removing special characters and keeping only alphanumeric characters
  for (i = 0; i < len; i++) {
    if (isalnum(str[i])) {
      sanitizedStr[j++] = str[i];
    }
  }
  sanitizedStr[j] = '\0';

  // Displaying the original and the sanitized string
  printf("The original string is: %s\n", str);
  printf("The sanitized string is: %s\n", sanitizedStr);
  return 0;
}