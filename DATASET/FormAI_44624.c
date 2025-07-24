//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
  char input[1000]; // declare the input buffer
  printf("Hey there! Let's generate a SHA256 hash!\n");
  printf("Enter the message you want to hash: ");
  scanf("%[^\n]", input); // get input from the user

  unsigned char output[SHA256_DIGEST_LENGTH]; // declare the output buffer
  SHA256(input, strlen(input), output); // generate the hash

  printf("The SHA256 hash of \"%s\" is: ", input);
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) { // loop through each byte of the hash
    printf("%02x", output[i]); // print each byte in hexadecimal format
  }

  printf("\n\nWow, that was so much fun generating that hash!\n");
  printf("Let's do it again sometime! Goodbye!\n");
  return 0;
}