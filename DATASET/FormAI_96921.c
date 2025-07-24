//FormAI DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  char new_str[100];
  int vowels = 0;

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  // Remove newline character from input string
  if (str[strlen(str) - 1] == '\n') {
    str[strlen(str) - 1] = '\0';
  }

  // Count number of vowels in input string
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      vowels++;
    }
  }

  // Reverse input string
  for (int i = 0, j = strlen(str) - 1; i < strlen(str); i++, j--) {
    new_str[i] = str[j];
  }
  new_str[strlen(str)] = '\0';

  // Output original string, number of vowels, and reversed string
  printf("Original String: %s\n", str);
  printf("Number of vowels: %d\n", vowels);
  printf("Reversed String: %s\n", new_str);

  return 0;
}