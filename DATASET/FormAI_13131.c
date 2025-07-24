//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
  char password[100];
  bool has_uppercase = false; 
  bool has_lowercase = false;
  bool has_digit = false;
  bool has_specialchar = false;  
  int length = 0;

  printf("Enter password: ");
  scanf("%s", password);

  for (int i = 0; password[i] != '\0'; i++) {
    char c = password[i];
    length++;

    if (isupper(c)) {
      has_uppercase = true;
    } else if (islower(c)) {
      has_lowercase = true;
    } else if (isdigit(c)) {
      has_digit = true;
    } else {
      has_specialchar = true;
    }
  }

  bool is_strong = length >= 12 && has_uppercase && has_lowercase && has_digit && has_specialchar;
  bool is_medium = length >= 8 && has_uppercase && has_lowercase && has_digit;
  bool is_weak = length >= 6 && (has_uppercase || has_lowercase) && has_digit;

  if (is_strong) {
    printf("Strong password\n");
  } else if (is_medium) {
    printf("Medium password\n");
  } else if (is_weak) {
    printf("Weak password\n");
  } else {
    printf("Password does not meet minimum requirements\n");
  }

  return 0;
}