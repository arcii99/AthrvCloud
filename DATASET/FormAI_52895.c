//FormAI DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50] = "Hello, ";
  char str2[50] = "world!";
  char result[100];

  // Concatenating two strings
  strcat(result, str1);
  strcat(result, str2);
  printf("Concatenated string: %s\n", result);

  // Finding the length of a string
  int len = strlen(result);
  printf("Length of concatenated string: %d\n", len);

  // Reversing a string
  int i = 0;
  int j = len - 1;
  while (i < j) {
    char temp = result[i];
    result[i] = result[j];
    result[j] = temp;
    i++;
    j--;
  }
  printf("Reversed string: %s\n", result);

  // Converting a string to uppercase
  char str3[50] = "Hello, world!";
  for (i = 0; i < strlen(str3); i++) {
    if (str3[i] >= 'a' && str3[i] <= 'z') {
      str3[i] = str3[i] - 32;
    }
  }
  printf("Uppercase string: %s\n", str3);

  // Converting a string to lowercase
  char str4[50] = "Hello, WORLD!";
  for (i = 0; i < strlen(str4); i++) {
    if (str4[i] >= 'A' && str4[i] <= 'Z') {
      str4[i] = str4[i] + 32;
    }
  }
  printf("Lowercase string: %s\n", str4);

  return 0;
}