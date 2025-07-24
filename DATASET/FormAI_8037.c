//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void encrypt(char msg[], int shift); // Function Declaration to encrypt plain text
void decrypt(char msg[], int shift); // Function Declaration to decrypt encrypted text

int main() {
  char message[MAX_LEN];
  int shift;

  printf("Enter message to encrypt: ");
  fgets(message, MAX_LEN, stdin); // Read message from user

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift); // Read shift amount from user

  // Encrypt message
  encrypt(message, shift);
  printf("Encrypted message: %s\n", message);

  // Decrypt message
  decrypt(message, shift);
  printf("Decrypted message: %s\n", message);

  return 0;
}

void encrypt(char msg[], int shift) {
  int i = 0;
  while (msg[i] != '\0') { // Iterate through each character in message
    if (msg[i] >= 'a' && msg[i] <= 'z') { // Check if character is a lowercase letter
      msg[i] = (msg[i] - 'a' + shift) % 26 + 'a'; // Apply shift to character
    }
    else if (msg[i] >= 'A' && msg[i] <= 'Z') { // Check if character is an uppercase letter
      msg[i] = (msg[i] - 'A' + shift) % 26 + 'A'; // Apply shift to character
    }
    i++;
  }
}

void decrypt(char msg[], int shift) {
  encrypt(msg, 26 - shift); // Decrypting is the same as encrypting with the inverse shift
}