//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#define MIN_LEN 8

int main(void) {
  char password[50];
  int len, digit = 0, special = 0, uppercase = 0, lowercase = 0;

  printf("Enter your password (at least %d characters long): ", MIN_LEN);
  scanf("%s", password);

  len = strlen(password);

  if(len < MIN_LEN) {
    printf("Your password is too short. Please make it at least %d characters long.\n", MIN_LEN);
    return 1;
  }

  for(int i = 0; i < len; i++) {
    if(isdigit(password[i])) {
      digit = 1;
    }
    else if(islower(password[i])) {
      lowercase = 1;
    }
    else if(isupper(password[i])) {
      uppercase = 1;
    }
    else if(!isalnum(password[i])) {
      special = 1;
    }
  }

  if(digit && special && lowercase && uppercase) {
    printf("Your password is strong. Congratulations!\n");
  }
  else {
    printf("Your password is weak. Please follow these guidelines:\n");
    printf("- Use a minimum of %d characters.\n", MIN_LEN);
    printf("- Use a combination of lowercase, uppercase, digits, and special characters.\n");
  }

  return 0;
}