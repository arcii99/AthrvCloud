//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char password[50];
  int len, digits, uppercase, lowercase, symbols, strength;
  int i;

  printf("Enter your password: ");
  fgets(password, 50, stdin);

  len = strlen(password) - 1;

  digits = uppercase = lowercase = symbols = 0;

  for (i = 0; password[i] != '\0'; i++) {
    if(password[i] >= '0' && password[i] <= '9') {
      digits++;
    }
    else if(password[i] >= 'A' && password[i] <= 'Z') {
      uppercase++;
    }
    else if(password[i] >= 'a' && password[i] <= 'z') {
      lowercase++;
    }
    else {
      symbols++;
    }
  }

  if(len < 8) {
    strength = 0;
  }
  else if(len >= 8 && len <= 10) {
    strength = 1;
  }
  else if(len >= 11 && len <= 14) {
    strength = 2;
  }
  else if(len >= 15) {
    strength = 3;
  }

  if(digits == 0) {
    strength--;
  }
  else if(digits == 1) {
    strength++;
  }
  else if(digits >= 2) {
    strength += 2;
  }

  if(uppercase == 0) {
    strength--;
  }
  else if(uppercase == 1) {
    strength++;
  }
  else if(uppercase >= 2) {
    strength += 2;
  }

  if(lowercase == 0) {
    strength--;
  }
  else if(lowercase == 1) {
    strength++;
  }
  else if(lowercase >= 2) {
    strength += 2;
  }

  if(symbols == 0) {
    strength--;
  }
  else if(symbols == 1) {
    strength++;
  }
  else if(symbols >= 2) {
    strength += 2;
  }

  if(strength < 0) {
    strength = 0;
  }
  else if(strength > 10) {
    strength = 10;
  }

  printf("Your password strength is %d out of 10.\n", strength);

  return 0;
}