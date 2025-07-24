//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[50];
  int length, i, upper, lower, digit, special;

  printf("Enter your password: ");
  scanf("%s", password);

  length = strlen(password);

  /* Check password length */
  if (length < 8 || length > 16) {
    printf("Password must be between 8 and 16 characters.\n");
    exit(0);
  }

  /* Check if password contains at least one upper, one lower, one digit and a special character */
  upper = lower = digit = special = 0;

  for (i = 0; i < length; i++) {
    if (isupper(password[i])) {
      upper = 1;
    }
    if (islower(password[i])) {
      lower = 1;
    }
    if (isdigit(password[i])) {
      digit = 1;
    }
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^') {
      special = 1;
    }
  }

  if (upper == 0 || lower == 0 || digit == 0 || special == 0) {
    printf("Password must contain at least one upper case letter, one lower case letter, one digit and a special character (!, @, #, $, %, ^).\n");
    exit(0);
  }

  printf("Password is strong.\n");

  return 0;
}