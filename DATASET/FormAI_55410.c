//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int passLength, i, randomIndex;
  char password[21];
  const char* symbols = "!@#$%^&*()_+-=,.<>?/:;\"{}[]\\|~`";
  const char* numbers = "0123456789";
  const char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char* lowercase = "abcdefghijklmnopqrstuvwxyz";
  
  srand(time(0));  // Set random seed

  printf("Welcome to Password Generator!\n");
  printf("How many characters would you like your password to be? (max 20): ");
  scanf("%d", &passLength);

  while (passLength > 20 || passLength < 1) {
    printf("Invalid length! Please enter a number between 1 and 20: ");
    scanf("%d", &passLength);
  }

  for (i = 0; i < passLength; i++) {
    randomIndex = rand() % 4;  // Choose one of the 4 character types randomly
    switch (randomIndex) {
      case 0:
        password[i] = symbols[rand() % 22];  // Get a random symbol from the symbols string
        break;
      case 1:
        password[i] = numbers[rand() % 10];  // Get a random number from the numbers string
        break;
      case 2:
        password[i] = uppercase[rand() % 26];  // Get a random uppercase letter from the uppercase string
        break;
      case 3:
        password[i] = lowercase[rand() % 26];  // Get a random lowercase letter from the lowercase string
        break;
    }
  }

  password[passLength] = '\0';  // Add null terminator at the end of string
  printf("Your generated password is: %s\n", password);

  return 0;
}