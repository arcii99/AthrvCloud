//FormAI DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];
  int key, i;

  printf("My love, please tell me your secret message:\n");
  gets(message);

  printf("My dearest, please give me a secret key, from 1 to 25:\n");
  scanf("%d", &key);

  // Encryption
  for(i = 0; message[i] != '\0'; i++) {
    if(message[i] >= 'a' && message[i] <= 'z') {
      message[i] = ((message[i] - 'a' + key) % 26) + 'a';
    } else if(message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = ((message[i] - 'A' + key) % 26) + 'A';
    }
  }

  printf("My dear, your encrypted message is:\n%s\n", message);

  // Decryption
  for(i = 0; message[i] != '\0'; i++) {
    if(message[i] >= 'a' && message[i] <= 'z') {
      message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
    } else if(message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
    }
  }

  printf("My sweet, your decrypted message is:\n%s\n", message);

  return 0;
}