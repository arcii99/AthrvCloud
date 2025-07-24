//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

#define MAX_LENGTH 100

int main() {

  printf("Enter a message to hash:\n");
  char message[MAX_LENGTH];
  fgets(message, MAX_LENGTH, stdin);

  // Remove newline character from input
  size_t len = strlen(message);
  if (len > 0 && message[len-1] == '\n') {
    message[--len] = '\0';
  }

  // Generate MD5 hash
  unsigned char digest[MD5_DIGEST_LENGTH];
  MD5_CTX context;
  MD5_Init(&context);
  MD5_Update(&context, message, strlen(message));
  MD5_Final(digest, &context);

  // Convert digest to human-readable string
  char hash[MAX_LENGTH*2+1];
  for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
    sprintf(hash+i*2, "%02x", digest[i]);
  }
  hash[MAX_LENGTH*2] = '\0';

  printf("The hash of \"%s\" is:\n%s\n", message, hash);

  return 0;
}