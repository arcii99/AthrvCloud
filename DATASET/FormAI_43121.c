//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
  char password[50];
  int length, hasLower = 0, hasUpper = 0, hasNumber = 0, hasSymbol = 0, strength = 0;

  printf("Please enter your password:\n");
  fgets(password, 50, stdin);

  length = strlen(password);

  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLower = 1;
    } else if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUpper = 1;
    } else if (password[i] >= '0' && password[i] <= '9') {
      hasNumber = 1;
    } else {
      hasSymbol = 1;
    }
  }

  if (length >= 8) {
    strength += 1;
  }
  if (hasLower) {
    strength += 1;
  }
  if (hasUpper) {
    strength += 1;
  }
  if (hasNumber) {
    strength += 1;
  }
  if (hasSymbol) {
    strength += 1;
  }

  printf("Your password strength is: %d/5\n", strength);

  return 0;
}