//FormAI DATASET v1.0 Category: Educational ; Style: protected
/*
This program allows the user to enter a password and then securely checks it's validity.
A password is considered valid if it is at least 8 characters long, contains at least one uppercase letter,
one lowercase letter, one digit, and at least one special character(!,@,#,$,%,&,*).
The password must not contain spaces.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 128

int main(void) {
  char password[MAX_PASSWORD_LENGTH];
  int valid = 1;
  int i, length, uppercase, lowercase, digit, special_char;

  printf("Please enter your password: ");
  fgets(password, MAX_PASSWORD_LENGTH, stdin);
  length = strlen(password);

  // Check for spaces
  for(i = 0; i < length; i++) {
    if(password[i] == ' ') {
      valid = 0;
      break;
    }
  }

  // Check length
  if(valid && length < 8) {
    valid = 0;
  }

  // Check for at least one uppercase, lowercase, digit, and special character
  if(valid) {
    uppercase = lowercase = digit = special_char = 0;

    for(i = 0; i < length; i++) {
      if(isupper(password[i])) {
        uppercase = 1;
      }
      else if(islower(password[i])) {
        lowercase = 1;
      }
      else if(isdigit(password[i])) {
        digit = 1;
      }
      else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*') {
        special_char = 1;
      }
    }

    if(!(uppercase && lowercase && digit && special_char)) {
      valid = 0;
    }
  }

  // Print result
  if(valid) {
    printf("Password is valid.\n");
  }
  else {
    printf("Invalid password.\n");
  }

  return 0;
}