//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: dynamic
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main() {
  char password[100];
  int len, score = 0;
  bool digit = false, upper = false, lower = false, special = false;
  
  printf("Enter your password: ");
  fgets(password, sizeof(password), stdin);
  len = strlen(password);
  password[len - 1] = '\0'; // remove the newline character
  
  for (int i = 0; i < len - 1; i++) {
    if (isdigit(password[i])) {
      digit = true;
      score += 2;
    } else if (isupper(password[i])) {
      upper = true;
      score += 3;
    } else if (islower(password[i])) {
      lower = true;
      score += 1;
    } else if (ispunct(password[i])) {
      special = true;
      score += 4;
    }
  }
  
  if (digit && upper && lower && special) {
    printf("Password strength: Excellent\n");
  } else if (upper && lower && special && score >= 10) {
    printf("Password strength: Good\n");
  } else if ((digit && upper && lower) || (upper && lower && special)) {
    printf("Password strength: Fair\n");
  } else {
    printf("Password strength: Weak\n");
  }
  
  return 0;
}