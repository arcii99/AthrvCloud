//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main(void) {
  char password[PASSWORD_LENGTH+1];
  char charset[] = "0123456789"\
                    "abcdefghijklmnopqrstuvwxyz"\
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"\
                    "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";
  int charset_size = sizeof(charset) - 1;

  srand(time(NULL));

  for(int i = 0; i < PASSWORD_LENGTH; i++){
    password[i] = charset[rand() % charset_size];
  }
  password[PASSWORD_LENGTH] = '\0';

  printf("Generated Password: %s", password);

  return 0;
}