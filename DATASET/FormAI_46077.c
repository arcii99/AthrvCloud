//FormAI DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char password[16];
  char secret_message[256] = "You have unlocked the secret message!";

  printf("Please enter the password to access the secret message: ");
  scanf("%s", password);

  // Encrypt the password to make it harder to guess
  for (int i = 0; i < strlen(password); i++) {
    password[i] = password[i] + 12;
  }

  // Check if the password is correct
  if (strcmp(password, "sbsvnkjjbkj10") != 0) {
    printf("Incorrect password. Access denied.\n");
    return 0;
  }

  // Decrypt the message and print it
  for (int i = 0; i < strlen(secret_message); i++) {
    secret_message[i] = secret_message[i] - 12;
  }

  printf("%s\n", secret_message);

  return 0;
}