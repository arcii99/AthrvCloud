//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h> // include the OpenSSL library for SHA hashing

// A cheerful cryptographic hash function example program!

int main() {

  char str[1000];
  unsigned char hashed[SHA256_DIGEST_LENGTH]; // buffer for storing the SHA256 hash
  int i;

  printf("Welcome to the Cheerful Cryptographic Hash Function Program!\n");
  printf("Please enter the string you want to hash: ");
  fgets(str, sizeof(str), stdin); // get user input

  // Hash the input string using SHA256 and store the result in hashed
  SHA256(str, strlen(str), hashed);

  printf("\nYour cheerful hash is: ");
  for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    printf("%02x",hashed[i]); // print the hash in hexadecimal format
  }

  printf("\n");
  return 0;
}