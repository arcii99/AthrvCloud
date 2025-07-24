//FormAI DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h> // for standard input/output functionality
#include <string.h> // for string functions

int main() {
  char message[1000], cipher[1000]; // declare two character arrays to store the message and the cipher respectively
  int key, i; // declare integer variables to store the key and the iteration index

  printf("Enter a message: ");
  fgets(message, sizeof(message), stdin); // get the message from the user

  printf("Enter a key (1-26): ");
  scanf("%d", &key); // get the key from the user

  // encryption process
  for(i = 0; i < strlen(message); i++) {
    if(message[i] >= 'a' && message[i] <= 'z') { // check if the character is lowercase
      cipher[i] = 'a' + ((message[i] - 'a' + key) % 26); // shift the character by the key value
    } else if(message[i] >= 'A' && message[i] <= 'Z') { // check if the character is uppercase
      cipher[i] = 'A' + ((message[i] - 'A' + key) % 26); // shift the character by the key value
    } else { // for non-alphabetic characters
      cipher[i] = message[i]; // copy the character as is
    }
  }

  printf("Encrypted message: %s", cipher); // print the encrypted message
  return 0; // return 0 to indicate successful execution
}