//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16

int main() {
  srand(time(NULL));
  
  char password[PASSWORD_LENGTH];
  int i, j, r;

  for (i = 0; i < PASSWORD_LENGTH; i++) {
    r = rand() % 3;
    if (r == 0) {
      password[i] = 'A' + rand() % 26;
    } else if (r == 1) {
      password[i] = 'a' + rand() % 26;
    } else {
      password[i] = '0' + rand() % 10;
    }
  }

  for (i = 0; i < PASSWORD_LENGTH - 1; i++) {
    for (j = i + 1; j < PASSWORD_LENGTH; j++) {
      if (password[i] > password[j]) {
        char tmp = password[i];
        password[i] = password[j];
        password[j] = tmp;
      }
    }
  }

  printf("Your new password is: %s\n", password);

  return 0;
}