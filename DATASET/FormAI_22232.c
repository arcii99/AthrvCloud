//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Shape-shifting function to check password strength
void checkPasswordStrength(char *password) {
  int passwordLength = strlen(password);
  int hasUpperCase = 0;
  int hasLowerCase = 0;
  int hasNumbers = 0;
  int hasSpecialCharacters = 0;
  int strengthScore = 0;

  for (int i = 0; i < passwordLength; i++) {
    if (isupper(password[i])) {
      hasUpperCase = 1;
    } else if (islower(password[i])) {
      hasLowerCase = 1;
    } else if (isdigit(password[i])) {
      hasNumbers = 1;
    } else {
      hasSpecialCharacters = 1;
    }
  }

  // Calculate the password strength score
  strengthScore = passwordLength * (hasUpperCase + hasLowerCase + hasNumbers + hasSpecialCharacters);

  // Shape-shift and print the password strength report
  switch(strengthScore) {
    case 0 ... 10:
      printf("Your password strength is weak.\n");
      break;
    case 11 ... 20:
      printf("Your password strength is moderate.\n");
      break;
    case 21 ... 30:
      printf("Your password strength is strong.\n");
      break;
    case 31 ... 40:
      printf("Your password strength is very strong.\n");
      break;
    default:
      printf("Your password strength cannot be determined.\n");
  }
}

int main() {
  char password[256];
  printf("Enter your password: ");
  fgets(password, 256, stdin);

  // Remove the newline character from fgets command
  password[strcspn(password, "\n")] = '\0';
  
  // Check the password strength
  checkPasswordStrength(password);

  return 0;
}