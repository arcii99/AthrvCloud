//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>

// This is my amazing encryption program!

int main() {

  printf("\nHello, friend! Welcome to my encryption program!\n\n");

  char message[100];
  printf("What message would you like to encrypt today?\n");
  scanf("%[^\n]s", message);

  // Let's shift each character in the message by 2 characters in ASCII order
  int shift = 2;
  for(int i=0; message[i] != '\0'; i++) {
    message[i] += shift;
  }

  printf("\nYour encrypted message is: %s\n", message);

  printf("\nThank you for using my encryption program! Enjoy your day!\n\n");

  return 0;
}