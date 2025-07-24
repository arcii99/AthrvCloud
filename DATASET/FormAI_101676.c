//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: funny
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main() {
  printf("Welcome to the Password Strength Checker!\n");
  printf("Please enter your password: ");

  char password[50];
  fgets(password, 50, stdin); // getting input from user

  int length = strlen(password);
  int score = 0;

  printf("\nAnalyzing your password");

  // Determining password strength based on length
  if (length > 8) {
    score += 50;
  } else if (length >= 6 && length <= 8) {
    score += 25;
  } else {
    printf("\nYour password is too short!");
    return;
  }

  // Checking for uppercase letters
  char *ptr = password;
  while (*ptr != '\0') {
    if (isupper(*ptr)) {
      score += 10;
      break;
    }
    ++ptr;
  }

  // Checking for lowercase letters
  ptr = password;
  while (*ptr != '\0') {
    if (islower(*ptr)) {
      score += 10;
      break;
    }
    ++ptr;
  }

  // Checking for digits
  ptr = password;
  while (*ptr != '\0') {
    if (isdigit(*ptr)) {
      score += 10;
      break;
    }
    ++ptr;
  }

  // Checking for special characters
  ptr = password;
  while (*ptr != '\0') {
    if ((*ptr >= 32 && *ptr <= 47) || (*ptr >= 58 && *ptr <= 64) || (*ptr >= 91 && *ptr <= 96) || (*ptr >= 123 && *ptr <= 126)) {
      score += 10;
      break;
    }
    ++ptr;
  }

  // Printing final score
  printf("\n\nYour password strength score is: %d", score);

  if (score >= 60) {
    printf("\nCongratulations! Your password is strong!");
  } else {
    printf("\nYour password is weak. Please try again.");
  }
}