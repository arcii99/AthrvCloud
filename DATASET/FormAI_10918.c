//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[100];
  int length, i;
  int uppercaseCount = 0, lowercaseCount = 0, digitCount = 0, specialCharCount = 0;

  printf("Enter password:\n");
  fgets(password, 100, stdin);
  password[strcspn(password, "\n")] = '\0'; // remove trailing newline character

  length = strlen(password);
  
  if (length < 8) {
    printf("Password is too short. Password strength: Weak\n");
    return 0;
  }
  
  for (i = 0; i < length; i++) {
    if (isupper(password[i])) {
      uppercaseCount++;
    }
    else if (islower(password[i])) {
      lowercaseCount++;
    }
    else if (isdigit(password[i])) {
      digitCount++;
    }
    else {
      specialCharCount++;
    }
  }

  if (uppercaseCount == 0 || lowercaseCount == 0 || digitCount == 0 || specialCharCount == 0) {
    printf("Password does not contain a mix of uppercase and lowercase letters, digits, and special characters. Password strength: Medium\n");
    return 0;
  }

  printf("Password strength: Strong\n");
  return 0;
}