//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 20 // maximum length for password
#define MIN_LENGTH 8 // minimum length for password

/* Function to generate random alphanumeric character */
char getRandomChar() {
  int num = rand() % 62;
  if (num < 10) return (char) ('0' + num);
  if (num < 36) return (char) ('a' + num - 10);
  return (char) ('A' + num - 36);
}

/* Function to generate a random password */
void generatePassword(char *password) {
  int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH; // generate random length
  for (int i = 0; i < length; i++) {
    password[i] = getRandomChar(); // add random character
  }
  password[length] = '\0'; // null terminator
}

/* Main function */
int main() {
  srand(time(NULL)); // seed random number generator

  char password[MAX_LENGTH + 1]; // holds password

  generatePassword(password); // generate password
  printf("Password: %s\n", password);

  return 0;
}