//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surprised
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
  char password[64];
  printf("Enter your password: ");
  fgets(password, 64, stdin);

  int len = strlen(password) - 1; // exclude newline character at the end
  int score = 0;
  int upper = 0;
  int lower = 0;
  int digits = 0;
  int symbols = 0;

  for (int i = 0; i < len; i++) {
    char c = password[i];
    if (isupper(c)) {
      upper++;
    }
    if (islower(c)) {
      lower++;
    }
    if (isdigit(c)) {
      digits++;
    }
    if (!isalnum(c)) {
      symbols++;
    }
  }

  if (len >= 8) {
    score += 10;
  }
  if (upper > 0 && lower > 0) {
    score += 20;
  } else if (upper > 0 || lower > 0) {
    score += 10;
  }
  if (digits > 0) {
    score += 20;
  }
  if (symbols > 0) {
    score += 30;
  }

  printf("Your password score is: %d\n", score);

  if (score >= 90) {
    printf("Wow, your password is super strong!");
  } else if (score >= 70) {
    printf("Not bad, your password is strong enough.");
  } else if (score >= 50) {
    printf("Hmm, your password could be stronger.");
  } else if (score >= 30) {
    printf("Your password is weak, consider changing it.");
  } else {
    printf("Your password is really weak, please change it immediately!");
  }

  return 0;
}