//FormAI DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
  char password[20];
  char compare[20] = "iloveyou";

  printf("My dearest, please enter the password to my heart: ");

  scanf("%s", password);

  if (strcmp(password, compare) == 0) {
    printf("Welcome to my heart, my love! Your password is correct.\n");
  } else {
    printf("Sorry, the password you entered is incorrect. You cannot enter my heart with that password!\n");
  }

  return 0;
}