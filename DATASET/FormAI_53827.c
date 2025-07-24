//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASS_LEN 16

void genPassword(char *password);

void genPassword(char *password) {
  const char passwordChars[] = "`~-_=+[{]}\\|;:'\",<.>/?"; // password characters
  int charIndex, i;

  srand((unsigned int) time(NULL));

  for (i = 0; i < PASS_LEN; i++) {
    charIndex = rand() % (sizeof(passwordChars) - 1);
    password[i] = passwordChars[charIndex];
  }
  password[i] = '\0';
}

int main() {
  char password[PASS_LEN + 1], c;
  int digitFlag = 0, upperFlag = 0, lowerFlag = 0, symbolFlag = 0, i;

  genPassword(password);

  printf("Generated Password: %s\n", password);

  for (i = 0; i < PASS_LEN; i++) {
    c = password[i];

    if (isdigit(c)) {
      digitFlag = 1;
    } else if (isupper(c)) {
      upperFlag = 1;
    } else if (islower(c)) {
      lowerFlag = 1;
    } else {
      symbolFlag = 1;
    }

    if (digitFlag && upperFlag && lowerFlag && symbolFlag) {
      break;
    }
  }

  if (digitFlag && upperFlag && lowerFlag && symbolFlag) {
    printf("Password meets complexity requirements\n");
  } else {
    printf("Password does not meet complexity requirements\n");
  }

  return 0;
}