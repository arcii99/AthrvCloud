//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 16
#define MIN_PASSWORD_LENGTH 8

int main(void) {
  char password[MAX_PASSWORD_LENGTH + 1]; // leave space for null terminator
  int password_length;
  bool has_lowercase = false, has_uppercase = false, has_number = false, has_special = false;

  // seed random number generator
  srand(time(NULL));

  // loop until all password requirements are met
  do {
    // choose a random length between MIN and MAX
    password_length = (rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1)) + MIN_PASSWORD_LENGTH;

    // reset flag variables
    has_lowercase = false, has_uppercase = false, has_number = false, has_special = false;

    // loop through each character in the password and assign a random value based on ASCII table
    for (int i = 0; i < password_length; i++) {
      int character_type = rand() % 4; // 0 for lowercase, 1 for uppercase, 2 for number, 3 for special
      int character_value;

      switch (character_type) {
        case 0: // lowercase character
          character_value = rand() % 26 + 97; // ASCII code for lowercase letters a-z
          has_lowercase = true;
          break;
        case 1: // uppercase character
          character_value = rand() % 26 + 65; // ASCII code for uppercase letters A-Z
          has_uppercase = true;
          break;
        case 2: // number character
          character_value = rand() % 10 + 48; // ASCII code for numbers 0-9
          has_number = true;
          break;
        case 3: // special character
          character_value = rand() % 15 + 33; // ASCII codes for common special characters !\"#$%&'()*+,-./
          has_special = true;
          break;
      }

      password[i] = (char) character_value;
    }

    password[password_length] = '\0'; // add null terminator to end of password string

  } while (!has_lowercase || !has_uppercase || !has_number || !has_special);

  printf("Secure Password Generated: %s\n", password);

  return 0;
}