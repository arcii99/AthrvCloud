//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[50];
  int upper = 0, lower = 0, digit = 0, special = 0, length = 0;

  printf("Please enter your password: ");
  scanf("%s", password);

  length = strlen(password);

  for(int i = 0; i < length; i++) {
    if(isupper(password[i])) {
      upper = 1;
    }
    else if(islower(password[i])) {
      lower = 1;
    }
    else if(isdigit(password[i])) {
      digit = 1;
    }
    else {
      special = 1;
    }
  }

  // checking the strength of the password
  if(length <= 6 || !upper || !lower || !digit || !special) {
    printf("Your password is weak. Please use a stronger password.");
  }
  else if(length <= 10 && upper && lower && digit && !special) {
    printf("Your password is moderate. Consider using special characters for added security.");
  }
  else {
    printf("Your password is strong. Keep up the good work!");
  }

  return 0;
}