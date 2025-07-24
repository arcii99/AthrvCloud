//FormAI DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
  // Declare two character arrays
  char str1[50], str2[50];

  // Get input from the user
  printf("Enter a string: ");
  fgets(str1, sizeof(str1), stdin);

  // Copy the string into the second array
  strcpy(str2, str1);

  // Get the length of the string
  int len = strlen(str1);

  // Print the string in reverse
  printf("Reversed string: ");
  for (int i = len - 1; i >= 0; i--) {
    printf("%c", str1[i]);
  }

  // Check if the strings are equal
  if (strcmp(str1, str2) == 0) {
    printf("\nThe strings are equal.\n");
  } else {
    printf("\nThe strings are different.\n");
  }

  // Concatenate the two strings
  strcat(str1, " ");
  strcat(str1, str2);
  printf("Concatenated string: %s\n", str1);

  // Convert the string to uppercase
  for (int i = 0; str1[i]; i++) {
    str1[i] = toupper(str1[i]);
  }
  printf("Uppercase string: %s\n", str1);

  // Convert the string to lowercase
  for (int i = 0; str1[i]; i++) {
    str1[i] = tolower(str1[i]);
  }
  printf("Lowercase string: %s\n", str1);

  return 0;
}