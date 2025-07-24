//FormAI DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
int main()
{
  char message[100]; // maximum message size
  int key = 12; // encryption key
  int choice, i;
  printf("Enter message to encrypt: ");
  fgets(message, 100, stdin); // take input message from user
  
  do {
    printf("\nSelect encryption choice:\n");
    printf("1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
  } while ((choice != 1) && (choice != 2)); // accept only 1 or 2

  for (i = 0; message[i] != '\0'; ++i) {
    // perform encryption
    if (choice == 1)
      message[i] += key;
    // perform decryption
    else
      message[i] -= key;
  }

  printf("Encrypted/Decrypted message: %s\n", message);
  return 0;
}