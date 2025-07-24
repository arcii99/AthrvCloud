//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program encrypts your secrets for you!

int main() {
  char secret[1000], key[1000];
  int secret_len, key_len;

  printf("Hello! I'm here to encrypt your secrets.\n");
  printf("Please enter your secret here: ");
  scanf("%s", secret);

  printf("Now please give me a key: ");
  scanf("%s", key);

  secret_len = strlen(secret);
  key_len = strlen(key);

  if (key_len != secret_len) {
    printf("Oops! Your secret and key should be of the same length.\n");
    printf("Here's a joke for you: Why was the computer cold? Because it left its Windows open!\n");
    return 1;
  }

  for (int i = 0; i < secret_len; i++) {
    secret[i] = ((secret[i] - 'a') + (key[i] - 'a')) % 26 + 'a';
  }

  printf("Your encrypted secret is: %s\n", secret);
  printf("If you ever want to decrypt it, use the same key [wink wink]\n");
  printf("Thanks for using our encryption service! Have a great day!\n");
  return 0;
}