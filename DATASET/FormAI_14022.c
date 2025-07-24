//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char message[100], ch;
  int key, i;

  printf("Enter a message to encrypt: ");
  fgets(message, sizeof(message), stdin);
  printf("Enter key: ");
  scanf("%d", &key);

  for(i = 0; message[i] != '\0'; ++i) {
    ch = message[i];

    if(ch >= 'a' && ch <= 'z') {
      ch = ch + key;

      if(ch > 'z') {
        ch = ch - 'z' + 'a' - 1;
      }

      message[i] = ch;
    }
    else if(ch >= 'A' && ch <= 'Z') {
      ch = ch + key;

      if(ch > 'Z') {
        ch = ch - 'Z' + 'A' - 1;
      }

      message[i] = ch;
    }
  }

  printf("Encrypted message: %s", message);

  return 0;
}