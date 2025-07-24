//FormAI DATASET v1.0 Category: modern Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

char * encrypt(char * message, char * key) {
  int i, j = 0, enc;
  char * result = malloc(sizeof(char) * MAX);
  srand(time(NULL));
  for(i = 0; i < strlen(message); i++) {
    if(j >= strlen(key)) {
      j = 0;
    }
    enc = ((int)key[j] * (int)message[i]) + rand();
    sprintf(result + strlen(result), "%d", enc);
    j++;
  }
  return result;
}

int main() {
  char * message = "Hello World"; // the message to be encrypted
  char * key = "secretkey"; // the encryption key

  printf("Original Message: %s\n", message);
  char * encrypted_message = encrypt(message, key);
  printf("Encrypted Message: %s\n", encrypted_message);

  free(encrypted_message);
  return 0;
}