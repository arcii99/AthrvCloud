//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[50];
  int key = 1234;

  printf("Enter a secret message: ");
  fgets(message, 50, stdin);

  for(int i = 0; i < strlen(message); i++) {
    int ascii_val = (int) message[i];
    ascii_val += key;
    message[i] = (char) ascii_val;
  }

  printf("Your encrypted message is: %s", message);

  return 0;
}

/*
 * This code encrypts your message using the power of your secret key!! 🔐💪🏼
 * It's like putting your message in a super-secret bank vault, except the vault is your key and the banker is this program 🏦😂
 * When you run this program, you may feel like a top-secret spy, but don't worry, your secret is safe with this encryption! 🕵️‍♀️🤫
 * Just remember to keep your key safe, because without it, your message is lost to the world forever! 🔒🌎
 * If you forget your key, you might as well forget about your message too, it's gone-zo! 🙅🏻‍♂️👋🏻
 * Good luck and happy encryption! 🤞🏼✨
 */