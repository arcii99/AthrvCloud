//FormAI DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[100];
  char substr[50];

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = 0; // Removing trailing newline

  printf("Enter a substring to search: ");
  fgets(substr, sizeof(substr), stdin);
  substr[strcspn(substr, "\n")] = 0; // Removing trailing newline

  // Get the length of the substring
  int substr_len = strlen(substr);

  // Search for the substring
  char *p = strstr(str, substr);
  if (p) {
    printf("'%s' is found at position %ld\n", substr, p - str);

    // Removing the substring from the original string
    memmove(p, p + substr_len, strlen(p + substr_len) + 1);
    printf("String after removal of substring: %s\n", str);
  } else {
    printf("'%s' is not found in the string.\n", substr);
  }

  // Reversing the string
  int len = strlen(str);
  char rev_str[len + 1];
  for (int i = 0; i < len; i++) {
    rev_str[len - i - 1] = str[i];
  }
  rev_str[len] = '\0';
  printf("Reversed string: %s\n", rev_str);

  // Making the string uppercase
  for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - ('a' - 'A');
    }
  }
  printf("Uppercased string: %s\n", str);

  return 0;
}