//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
  char password[100];
  int length, upper = 0, lower = 0, digits = 0, special = 0;

  printf("Enter your password : ");
  scanf("%s", password);

  length = strlen(password);

  for(int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      upper = 1;
    }
    else if (password[i] >= 'a' && password[i] <= 'z') {
      lower = 1;
    }
    else if (password[i] >= '0' && password[i] <= '9') {
      digits = 1;
    }
    else {
      special = 1;
    }
  }

  if (length >= 8 && upper && lower && digits && special) {
    printf("Your password is strong!\n");
  }
  else {
    printf("Your password is weak!\n");
    printf("Please make sure your password has at least 8 characters, one uppercase letter, one lowercase letter, one digit, and one special character.\n");
  }

  return 0;
}