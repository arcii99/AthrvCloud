//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[20];
  int i, length, hasUpper, hasLower, hasDigit, hasSpecial;

  printf("Enter password: ");
  scanf("%s", password);

  length = strlen(password);

  if (length < 8) {
    printf("Password must be at least 8 characters long\n");
    return 0;
  }

  hasUpper = 0;
  hasLower = 0;
  hasDigit = 0;
  hasSpecial = 0;

  for (i = 0; i < length; i++) {
    if (isupper(password[i])) {
      hasUpper = 1;
    } else if (islower(password[i])) {
      hasLower = 1;
    } else if (isdigit(password[i])) {
      hasDigit = 1;
    } else if (!isalnum(password[i])) {
      hasSpecial = 1;
    }
  }

  if (!hasUpper || !hasLower || !hasDigit || !hasSpecial) {
    printf("Password must contain at least one uppercase letter, one lowercase letter, one digit and one special character\n");
    return 0;
  }

  printf("Password is strong!\n");

  return 0;
}