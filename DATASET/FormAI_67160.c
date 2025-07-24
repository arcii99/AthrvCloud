//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

void generatePassword(char password[]) {
  char possibleCharacters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-=+{}[]<>,.?/|";
  int possibleCharactersLength = strlen(possibleCharacters);

  srand(time(NULL));

  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    int randomIndex = rand() % possibleCharactersLength;
    char randomCharacter = possibleCharacters[randomIndex];
    password[i] = randomCharacter;
  }

  password[PASSWORD_LENGTH] = '\0';
}

int main() {
  char password[PASSWORD_LENGTH + 1];
  
  generatePassword(password);

  printf("Generated Password: %s\n", password);

  return 0;
}