//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check for special characters
int hasSpecialChar(char* password) {
  for(int i = 0; i < strlen(password); i++) {
    if(ispunct(password[i])) {
      return 1;
    }
  }
  return 0;
}

// function to check for lowercase letters
int hasLowerCase(char* password) {
  for(int i = 0; i < strlen(password); i++) {
    if(islower(password[i])) {
      return 1;
    }
  }
  return 0;
}

// function to check for uppercase letters
int hasUpperCase(char* password) {
  for(int i = 0; i < strlen(password); i++) {
    if(isupper(password[i])) {
      return 1;
    }
  }
  return 0;
}

// function to check for numbers
int hasNumber(char* password) {
  for(int i = 0; i < strlen(password); i++) {
    if(isdigit(password[i])) {
      return 1;
    }
  }
  return 0;
}

// function to check password strength
int checkPasswordStrength(char* password) {
  int strength = 0;

  if(strlen(password) >= 8) {
    strength++;
  }
  
  if(hasSpecialChar(password)) {
    strength++;
  }
  
  if(hasLowerCase(password)) {
    strength++;
  }
  
  if(hasUpperCase(password)) {
    strength++;
  }
  
  if(hasNumber(password)) {
    strength++;
  }

  return strength;
}

int main() {
  char password[256];

  printf("Enter a password: ");
  fgets(password, 256, stdin);
  password[strcspn(password, "\n")] = 0;

  int strength = checkPasswordStrength(password);

  switch(strength) {
    case 0:
      printf("Your password is weak.\n");
      break;
    case 1:
      printf("Your password is moderately strong.\n");
      break;
    case 2:
      printf("Your password is strong.\n");
      break;
    case 3:
      printf("Your password is very strong.\n");
      break;
    case 4:
      printf("Your password is extremely strong.\n");
      break;
    default:
      printf("Error: Invalid password strength.\n");
  }

  return 0;
}