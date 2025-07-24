//FormAI DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>

// Hooray! We're going to make some encryption magic today! 
int main(void) {

  char message[1000];
  int key; 
  int i = 0;

  printf("Welcome! Enter the message you want to encrypt: ");
  fgets(message, sizeof(message), stdin); 

  printf("Sweet! Now, choose a number between 1 and 25 as your secret key: ");
  scanf("%d", &key);

  // Let's get started with the encryption fun! 
  while (message[i] != '\0') {
     
    char character = message[i];

    if (character >= 'a' && character <= 'z') {
      character = character + key;
      if (character > 'z') {
        character = character - 'z' + 'a' - 1;
      }
      message[i] = character;
    } else if (character >= 'A' && character <= 'Z') {
      character = character + key;
      if (character > 'Z') {
        character = character - 'Z' + 'A' - 1;
      }
      message[i] = character;
    }

    i++;
  }

  printf("Yay! Here's your encrypted message (drumroll please....): %s\n", message);

  return 0;
}