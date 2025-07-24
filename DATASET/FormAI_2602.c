//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[20];
  int length, has_uppercase, has_lowercase, has_digit, has_symbol;

  printf("Enter your password: ");
  scanf("%s", password);

  length = strlen(password);

  has_uppercase = 0;
  has_lowercase = 0;
  has_digit = 0;
  has_symbol = 0;

  for (int i = 0; i < length; i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
    } else if (islower(password[i])) {
      has_lowercase = 1;
    } else if (isdigit(password[i])) {
      has_digit = 1;
    } else {
      has_symbol = 1;
    }
  }

  if (length < 8 || length > 20) {
    printf("Your password must be between 8 and 20 characters long.\n");
  } else if (!(has_uppercase && has_lowercase && has_digit && has_symbol)) {
    printf("Your password must contain at least one uppercase letter, one lowercase letter, one digit, and one symbol.\n");
  } else {
    printf("Your password is strong.\n");
  }

  return 0;
}