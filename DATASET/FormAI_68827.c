//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void strip_punctuation(char *str);
void to_lowercase(char *str);
int is_palindrome(char *str);

int main(void) {
  char str[MAX_LENGTH];

  printf("Enter a string to check if it's a palindrome: ");
  fgets(str, MAX_LENGTH, stdin);
  
  strip_punctuation(str);
  to_lowercase(str);

  if (is_palindrome(str)) {
    printf("'%s' is a palindrome!\n", str);
  } else {
    printf("'%s' is not a palindrome.\n", str);
  }

  return 0;
}

void strip_punctuation(char *str) {
  char stripped[MAX_LENGTH];
  int j = 0;

  for (int i = 0; i < strlen(str); i++) {
    if (isalnum(str[i])) {
      stripped[j] = str[i];
      j++;
    }
  }

  stripped[j] = '\0';
  strcpy(str, stripped);
}

void to_lowercase(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
}

int is_palindrome(char *str) {
  int length = strlen(str);
  int i, j;

  for (i = 0, j = length - 1; i < j; i++, j--) {
    if (str[i] != str[j]) {
      return 0; // not a palindrome
    }
  }

  return 1; // palindrome
}