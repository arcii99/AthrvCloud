//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: realistic
/* C Password Strength Checker example program
   This program evaluates the strength of a given password based on
   various criteria such as length, complexity and uniqueness.
   Input: password string
   Output: password strength score and message
*/

#include <stdio.h>
#include <string.h>

int main() {
  char password[50];

  printf("Enter password: ");
  fgets(password, sizeof(password), stdin);

  int length = strlen(password);
  int score = 0;

  // Check for minimum length requirement
  if (length >= 8) {
    score += 25;
  } else {
    printf("Password must be at least 8 characters long.\n");
  }

  // Check for complexity requirements
  int has_uppercase = 0;
  int has_lowercase = 0;
  int has_digit = 0;
  int has_special = 0;

  for (int i = 0; i < length; i++) {
    char c = password[i];

    if (c >= 'A' && c <= 'Z') {
      has_uppercase = 1;
    } else if (c >= 'a' && c <= 'z') {
      has_lowercase = 1;
    } else if (c >= '0' && c <= '9') {
      has_digit = 1;
    } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^') {
      has_special = 1;
    }
  }

  if (has_uppercase && has_lowercase) {
    score += 25;
  } else {
    printf("Password must contain both uppercase and lowercase letters.\n");
  }

  if (has_digit && has_special) {
    score += 25;
  } else {
    printf("Password must contain both digits and special characters.\n");
  }

  // Check for uniqueness
  int unique_length = 0;
  int unique_characters[length];

  for (int i = 0; i < length; i++) {
    char c = password[i];
    int is_unique = 1;

    for (int j = 0; j < unique_length; j++) {
      if (unique_characters[j] == c) {
        is_unique = 0;
        break;
      }
    }

    if (is_unique) {
      unique_characters[unique_length] = c;
      unique_length++;
    }
  }

  if (unique_length >= length / 2) {
    score += 25;
  } else {
    printf("Password must have at least 50 percent unique characters.\n");
  }

  // Output password strength score and message
  if (score == 100) {
    printf("Password is very strong!\n");
  } else if (score >= 75) {
    printf("Password is strong.\n");
  } else if (score >= 50) {
    printf("Password is moderate.\n");
  } else {
    printf("Password is weak.\n");
  }

  printf("Password strength score: %d/100\n", score);

  return 0;
}