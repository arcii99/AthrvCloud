//FormAI DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
  char str[100], temp;
  int i, j, len;

  printf("Enter a string: ");
  scanf("%s", str);

  len = strlen(str);

  // Reverse the string
  for (i = 0, j = len - 1; i < j; i++, j--) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }

  printf("Reversed string: %s\n", str);

  // Remove all vowels from the string
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
          || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      for (j = i; str[j] != '\0'; j++) {
        str[j] = str[j+1];
      }
      i--;
    }
  }

  printf("String without vowels: %s\n", str);

  // Check if the string is a palindrome
  for (i = 0, j = len - 1; i < j; i++, j--) {
    if (str[i] != str[j]) {
      printf("The string is not a palindrome.\n");
      return 0;
    }
  }

  printf("The string is a palindrome.\n");

  return 0;
}