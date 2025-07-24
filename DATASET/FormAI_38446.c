//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main() {

  char password[PASSWORD_LENGTH + 1];
  char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[]|\\:;<>,.?/";

  srand(time(NULL));

  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    int index = rand() % (sizeof(charset) - 1);
    password[i] = charset[index];
  }

  password[PASSWORD_LENGTH] = '\0';

  printf("Your secure password is: %s\n", password);

  return 0;
}