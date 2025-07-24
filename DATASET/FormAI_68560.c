//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: careful
/*
 * C Secure Password Generator
 * Description: This program generates secure passwords 
 * for users who wants to increase their online security.
 * Author: Your Name
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12  // define password length constant
#define SPECIAL_CHARS "!@#$%^&*()_+-=<>?,./"  // define special characters

int main() {
  char password[PASSWORD_LENGTH+1];  // password string
  int i;
  int num_digits = 0;  // number of digits in password
  int num_upper = 0;   // number of uppercase letters in password
  int num_lower = 0;   // number of lowercase letters in password
  int num_special = 0; // number of special characters in password
  
  // set the seed for the random number generator
  srand(time(NULL));
  
  // loop to generate password with specified requirements
  while (num_digits < 2 || num_upper < 2 || num_lower < 2 || num_special < 2) {
    for (i = 0; i < PASSWORD_LENGTH; i++) {
      int rand_num = rand() % 4;
      if (rand_num == 0 && num_digits < 2) {
        password[i] = (rand() % 10) + '0';  // add digit to password
        num_digits++;
      } else if (rand_num == 1 && num_upper < 2) {
        password[i] = (rand() % 26) + 'A';  // add uppercase letter to password
        num_upper++;
      } else if (rand_num == 2 && num_lower < 2) {
        password[i] = (rand() % 26) + 'a';  // add lowercase letter to password
        num_lower++;
      } else if (rand_num == 3 && num_special < 2) {
        password[i] = SPECIAL_CHARS[rand() % 20];  // add special character to password
        num_special++;
      } else {
        password[i] = (rand() % 93) + 33;  // add random printable ASCII character to password
      }
    }
  }
  
  // add null terminator to password string
  password[PASSWORD_LENGTH] = '\0';
  
  // print password to console
  printf("Generated Password: %s\n", password);
  
  // validate password
  int is_valid = 1;
  for (i = 0; i < PASSWORD_LENGTH; i++) {
    if (isdigit(password[i])) {
      num_digits++;
    } else if (isupper(password[i])) {
      num_upper++;
    } else if (islower(password[i])) {
      num_lower++;
    } else if (strchr(SPECIAL_CHARS, password[i])) {
      num_special++;
    } else {
      is_valid = 0;
    }
  }
  
  // print password strength information
  printf("Password Strength:\n");
  printf("- Length: %d (Minimum 12 characters recommended)\n", PASSWORD_LENGTH);
  printf("- Number of Digits: %d (Minimum 2 recommended)\n", num_digits);
  printf("- Number of Uppercase Letters: %d (Minimum 2 recommended)\n", num_upper);
  printf("- Number of Lowercase Letters: %d (Minimum 2 recommended)\n", num_lower);
  printf("- Number of Special Characters: %d (Minimum 2 recommended)\n", num_special);
  
  // print password validity information
  if (is_valid) {
    printf("Password is Valid.\n");
  } else {
    printf("Password is Invalid.\n");
  }
  
  return 0;
}