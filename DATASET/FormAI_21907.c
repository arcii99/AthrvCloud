//FormAI DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[100], ch;
  int key, i;

  // Get message input
  printf("Enter a message to encrypt: ");
  fgets(message, 100, stdin);

  // Get key input
  printf("Enter key: ");
  scanf("%d", &key);

  // Loop through each character in message
  for(i = 0; message[i] != '\0'; ++i){
    ch = message[i];

    // Encrypt uppercase letters
    if(ch >= 'A' && ch <= 'Z'){
      ch = ch + key;

      if(ch > 'Z'){
        ch = ch - 'Z' + 'A' - 1;
      }

      message[i] = ch;
    }
    // Encrypt lowercase letters
    else if(ch >= 'a' && ch <= 'z'){
      ch = ch + key;

      if(ch > 'z'){
        ch = ch - 'z' + 'a' - 1;
      }

      message[i] = ch;
    }
  }

  // Print final encrypted message
  printf("Encrypted message: %s", message);

  return 0;
}