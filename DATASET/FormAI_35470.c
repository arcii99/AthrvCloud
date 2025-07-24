//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
  char input[1024];
  unsigned char output[SHA_DIGEST_LENGTH];

  printf("Welcome to my happy hash function!\n");
  printf("Please enter a string to hash: ");

  // Read input from user
  fgets(input, 1024, stdin);

  // Remove newline character from input
  input[strcspn(input, "\n")] = 0;

  // Hash the input using SHA256
  SHA256((unsigned char*) input, strlen(input), output);

  printf("The hash of \"%s\" is: ", input);

  // Print output as hexadecimal
  for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
    printf("%02x", output[i]);
  }

  printf("\nThank you for using my happy hash function!\n");

  return 0;
}