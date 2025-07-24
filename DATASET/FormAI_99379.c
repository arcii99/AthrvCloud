//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char password[25], strength[10];
  int length, i = 0, is_digit = 0, is_alpha = 0, is_special = 0;

  printf("Enter your password: ");
  scanf("%s", password);

  length = strlen(password);

  // Check for minimum length of 8 characters
  if (length < 8) {
    strcpy(strength, "Weak");
  }
  else {
    // Check for at least one digit, one alphabet and one special character
    while (password[i]) {
      if (isdigit(password[i])) {
        is_digit = 1;
      }
      else if (isalpha(password[i])) {
        is_alpha = 1;
      }
      else {
        is_special = 1;
      }
      i++;
    }
    if (is_digit && is_alpha && is_special) {
      strcpy(strength, "Strong");
    }
    else {
      strcpy(strength, "Moderate");
    }
  }

  printf("Your password is %s.\n", strength);

  return 0;
}