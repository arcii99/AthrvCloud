//FormAI DATASET v1.0 Category: String manipulation ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
  char string1[MAX_STRING_LENGTH];
  char string2[MAX_STRING_LENGTH];
  int length1, length2;

  printf("Enter the first string: ");
  fgets(string1, MAX_STRING_LENGTH, stdin);

  printf("Enter the second string: ");
  fgets(string2, MAX_STRING_LENGTH, stdin);

  length1 = strlen(string1);
  length2 = strlen(string2);

  printf("The length of the first string is: %d\n", length1);
  printf("The length of the second string is: %d\n", length2);

  printf("The first string is: %s", string1);
  printf("The second string is: %s", string2);

  // concatenate the two strings together and print
  strcat(string1, string2);
  printf("The concatenated string is: %s", string1);

  // check if the first string is equal to the second string
  if (strcmp(string1, string2) == 0) {
    printf("The two strings are equal.\n");
  } else {
    printf("The two strings are not equal.\n");
  }

  // copy string2 into string1 and print
  strcpy(string1, string2);
  printf("The first string is now: %s", string1);

  // reverse string2 and print
  length2 = strlen(string2);
  for (int i = length2 - 1; i >= 0; i--) {
    printf("%c", string2[i]);
  }
  printf("\n");

  return 0;
}