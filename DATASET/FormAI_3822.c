//FormAI DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main() {
  char input_str[100];
  printf("Enter a string: ");
  fgets(input_str, 100, stdin); // read input string from user

  // Convert every other character to uppercase
  for (int i = 0; i < strlen(input_str); i++) {
    if (i % 2 == 0) {
      if (input_str[i] >= 'a' && input_str[i] <= 'z') {
        input_str[i] -= 32;
      }
    }
  }
  printf("String with characters in even positions converted to uppercase: %s", input_str);

  // Reverse the string
  char reverse_str[strlen(input_str)];
  int j = 0;
  for (int i = strlen(input_str) - 1; i >= 0; i--) {
    reverse_str[j++] = input_str[i];
  }
  reverse_str[strlen(input_str)] = '\0';
  printf("String reversed: %s", reverse_str);

  // Remove all vowels from the string and print it
  for (int i = 0; i < strlen(input_str); i++) {
    if (input_str[i] == 'a' || input_str[i] == 'e' || input_str[i] == 'i' || input_str[i] == 'o' || input_str[i] == 'u' || 
        input_str[i] == 'A' || input_str[i] == 'E' || input_str[i] == 'I' || input_str[i] == 'O' || input_str[i] == 'U') {
      for (int j = i; j < strlen(input_str); j++) {
        input_str[j] = input_str[j + 1];
      }
      i--; // decrease i since a character is removed
    }
  }
  printf("String with vowels removed: %s", input_str);

  return 0;
}