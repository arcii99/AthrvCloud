//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define MAX_INPUT_SIZE 1000

int main()
{

  printf("Enter your message: ");

  char message[MAX_INPUT_SIZE];
  fgets(message, MAX_INPUT_SIZE, stdin);

  // Generate Salt
  char salt[4];
  srand(time(NULL));
  for(int i=0; i<4; i++) {
    salt[i] = rand() % 256;
  }

  // Hash the message with SHA-256
  unsigned char digest[SHA256_DIGEST_LENGTH];
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, (unsigned char*)message, strlen(message));
  SHA256_Update(&ctx, (unsigned char*)salt, sizeof(salt));
  SHA256_Final(digest, &ctx);

  // Print the Salt and Digested message
  printf("Salt: ");
  for(int i=0; i<4; i++) {
    printf("%x", salt[i]);
  }
  printf("\n");

  printf("Digested message: ");
  for(int i=0; i<SHA256_DIGEST_LENGTH; i++) {
    printf("%02x", digest[i]);
  }
  printf("\n");

  return 0;
}