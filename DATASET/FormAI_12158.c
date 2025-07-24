//FormAI DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  // Welcome message
  printf("Enter word or phrase to encrypt: ");

  // Variable to hold user input
  char input[100];
  fgets(input, 100, stdin);

  srand(time(NULL));

  // Encrypting the text
  for (int i = 0; i < strlen(input); i++) {

    // Randomly generate key value
    int key = rand() % 100;

    // XOR operation to encrypt the character
    input[i] = input[i] ^ key;
  }

  // Outputting the encrypted text
  printf("Encrypted text: %s\n", input);

  // Decryption process
  printf("Would you like to decrypt this encrypted text? (Y/N): ");

  // Variable for user input to decrypt
  char decision[2];
  fgets(decision, 2, stdin);

  // User chooses to decrypt
  if (decision[0] == 'Y' || decision[0] == 'y') {

    // Decrypting the text back to normal
    for (int i = 0; i < strlen(input); i++) {

      // Randomly generated key value is used to decrypt
      int key = rand() % 100;

      // XOR operation again to decrypt the character
      input[i] = input[i] ^ key;
    }

    // Outputting the decrypted text
    printf("Decrypted text: %s\n", input);
  }

  return 0;
}