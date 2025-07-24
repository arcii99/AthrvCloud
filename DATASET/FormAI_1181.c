//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROT13_SHIFT 13
#define VIGENERE_KEY "SECRETKEY"

int main(void) {
  char message[100];
  printf("Enter a message: ");
  fgets(message, sizeof(message), stdin);
  
  // ROT13 Cipher implementation
  for (int i = 0; i < strlen(message); i++) {
  	if (isalpha(message[i])) {
  	  if (isupper(message[i])) {
  	    message[i] = ((message[i] + ROT13_SHIFT - 'A') % 26) + 'A';
  	  } else {
  	    message[i] = ((message[i] + ROT13_SHIFT - 'a') % 26) + 'a';
  	  }
  	}
  }
  
  printf("ROT13 Cipher: %s", message);
  
  // Vigenere Cipher implementation
  int keyLength = strlen(VIGENERE_KEY);
  int messageLength = strlen(message);
  char encryptedMessage[100];
  
  for (int i = 0, j = 0; i < messageLength; ++i, ++j) {
  	if (j == keyLength) j = 0;
  	
  	if (isalpha(message[i])) {
  	  char key = toupper(VIGENERE_KEY[j]);
  	  encryptedMessage[i] = (((toupper(message[i]) - 'A') + (key - 'A')) % 26) + 'A';
  	} else {
  	  encryptedMessage[i] = message[i];
  	  --j;
  	}
  }
  
  printf("Vigenere Cipher: %s", encryptedMessage);
  
  return 0;
}