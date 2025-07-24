//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
  printf("Welcome to the C String manipulation program!\n\n");

  char str1[50] = "Hello, ";
  char str2[] = "world!";
  char str3[100];

  printf("Let's start by concatenating two strings:\n");
  printf("String 1: %s\n", str1);
  printf("String 2: %s\n\n", str2);

  strcat(str1, str2);

  printf("Result: %s\n\n", str1);

  printf("Now, let's copy a string:\n");
  char originalStr[] = "I love C programming!";
  char copiedStr[strlen(originalStr) + 1];

  strcpy(copiedStr, originalStr);

  printf("Original string: %s\n", originalStr);
  printf("Copied string: %s\n\n", copiedStr);

  printf("Let's compare two strings now:\n");
  char str4[10] = "apple";
  char str5[10] = "orange";

  int result = strcmp(str4, str5);

  if (result == 0) {
    printf("The strings are equal.\n\n");
  } else if (result < 0) {
    printf("%s comes before %s in alphabetical order.\n\n", str4, str5);
  } else {
    printf("%s comes after %s in alphabetical order.\n\n", str4, str5);
  }

  printf("Lastly, let's modify a string:\n");
  char originalGreeting[] = "Good morning, my friend!";
  printf("Original greeting: %s\n", originalGreeting);

  for (int i = 0; i < strlen(originalGreeting); i++) {
    if (originalGreeting[i] == ' ') {
      originalGreeting[i] = '-';
    }
  }

  printf("Modified greeting: %s\n", originalGreeting);

  return 0;
}