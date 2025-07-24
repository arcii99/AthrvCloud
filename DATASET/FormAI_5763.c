//FormAI DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
  char string[100], temp;
  int i, j, length;

  printf("Enter a string: ");
  scanf("%s", string);

  length = strlen(string);

  //reverse the string
  for (i = 0, j = length - 1; i < j; i++, j--) {
    temp = string[i];
    string[i] = string[j];
    string[j] = temp;
  }

  //count the vowels
  int vowels = 0;
  for (i = 0; string[i] != '\0'; i++) {
    if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i'
        || string[i] == 'o' || string[i] == 'u') {
      vowels++;
    }
  }

  //convert every letter to uppercase
  for (i = 0; i < length; i++) {
    if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] = string[i] - 32;
    }
  }

  printf("\nReversed string: %s", string);
  printf("\nNumber of vowels: %d", vowels);
  printf("\nUppercase string: %s", string);

  return 0;
}