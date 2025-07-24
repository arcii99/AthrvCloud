//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryption(char* message, int shift); // function to encrypt message
void decryption(char* cipher, int shift); // function to decrypt cipher

int main() {
  char message[100];
  int shift;

  // take input of message and shift from user
  printf("Enter a message to encrypt: ");
  fgets(message, 100, stdin);
  printf("Enter the shift amount (1-25): ");
  scanf("%d", &shift);
  
  // encrypt the message
  encryption(message, shift);

  printf("Encrypted message: %s\n", message);

  // decrypt the message
  decryption(message, shift);

  printf("Decrypted message: %s\n", message);

  return 0;
}

void encryption(char* message, int shift) {
  int i;
  char ch;
  
  for(i = 0; i < strlen(message); i++) {
    ch = message[i];

    if(ch >= 'A' && ch <= 'Z') {
      ch = ch + shift;

      if(ch > 'Z') {
        ch = ch - 'Z' + 'A' - 1;
      }

      message[i] = ch;
    }
    else if(ch >= 'a' && ch <= 'z') {
      ch = ch + shift;

      if(ch > 'z') {
        ch = ch - 'z' + 'a' - 1;
      }

      message[i] = ch;
    }
  }
}

void decryption(char* cipher, int shift) {
  int i;
  char ch;
  
  for(i = 0; i < strlen(cipher); i++) {
    ch = cipher[i];

    if(ch >= 'A' && ch <= 'Z') {
      ch = ch - shift;

      if(ch < 'A') {
        ch = ch + 'Z' - 'A' + 1;
      }

      cipher[i] = ch;
    }
    else if(ch >= 'a' && ch <= 'z') {
      ch = ch - shift;

      if(ch < 'a') {
        ch = ch + 'z' - 'a' + 1;
      }

      cipher[i] = ch;
    }
  }
}