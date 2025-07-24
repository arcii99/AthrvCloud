//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main(void) {
  char passwd[50];
  int len, i, has_digit=0, has_lower=0, has_upper=0, has_symbol=0;

  printf("Please enter your password: ");
  scanf("%s", passwd);
  len = strlen(passwd);
  
  for (i = 0; i < len; i++) {
    if(isdigit(passwd[i])) {
      has_digit = 1;
    } else if(islower(passwd[i])) {
      has_lower = 1;
    } else if(isupper(passwd[i])) {
      has_upper = 1;
    } else {
      has_symbol = 1;
    }
  }

  if(has_digit && has_lower && has_upper && has_symbol && len >= 8) {
    printf("Awesome! Your password is really strong.");
  } else if((has_digit && has_lower && has_upper && len >= 8) || (has_digit && has_lower && has_symbol && len >= 8) || (has_digit && has_upper && has_symbol && len >= 8) || (has_lower && has_upper && has_symbol && len >= 8)) {
    printf("Good job! Your password is strong, but can be stronger.");
  } else {
    printf("Uh oh, your password is weak. Try adding more characters such as numbers, lowercase letters, uppercase letters, and symbols. Make sure it is at least 8 characters long.");
  }

  return 0;
}