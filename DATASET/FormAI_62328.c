//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main(void) {
  int i;
  char password[PASSWORD_LENGTH + 1];
  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  srand((unsigned) time(NULL));

  printf("Generating Secure Password...\n");

  for (i = 0; i < PASSWORD_LENGTH; ++i) {
    int randomIndex = rand() % sizeof(charset);
    password[i] = charset[randomIndex];
  }

  password[PASSWORD_LENGTH] = '\0'; // Null-terminate the string
  printf("Your Secure Password is:\n%s\n", password);

  return 0;
}