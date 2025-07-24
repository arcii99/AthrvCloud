//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int generateRandomNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

void generatePassword(char *password) {
  srand(time(NULL));
  const char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
  const char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char specialCharacters[] = "@$!%*?&";
  const char numbers[] = "0123456789";

  int i;
  for (i = 0; i < PASSWORD_LENGTH; i++) {
    int randomNumber = generateRandomNumber(1, 4);
    if (randomNumber == 1) {
      int randomIndex = generateRandomNumber(0, 25);
      password[i] = lowercaseLetters[randomIndex];
    } else if (randomNumber == 2) {
      int randomIndex = generateRandomNumber(0, 25);
      password[i] = uppercaseLetters[randomIndex];
    } else if (randomNumber == 3) {
      int randomIndex = generateRandomNumber(0, 7);
      password[i] = specialCharacters[randomIndex];
    } else if (randomNumber == 4) {
      int randomIndex = generateRandomNumber(0, 9);
      password[i] = numbers[randomIndex];
    }
  }
  password[i] = '\0';
}

int main(void) {
  char password[PASSWORD_LENGTH + 1];
  generatePassword(password);
  printf("Your secure password is: %s\n", password);
  return 0;
}