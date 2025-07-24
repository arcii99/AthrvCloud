//FormAI DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <string.h>

int main() {
  char string[100];
  int n;

  printf("Enter a string: ");
  scanf("%s", &string);

  n = strlen(string);

  printf("Your string is %d characters long.\n", n);

  // Manipulating the string
  for (int i = 0; i < n; i++) {
    if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] -= 32; // Converting lowercase letters to uppercase
    } else if (string[i] >= 'A' && string[i] <= 'Z') {
      string[i] += 32; // Converting uppercase letters to lowercase
    }
  }

  printf("Your modified string is: %s\n", string);

  return 0;
}