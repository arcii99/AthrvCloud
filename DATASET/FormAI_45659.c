//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {

  char message[100], ch;
  int key, i;

  printf("Enter a message to encrypt: ");
  gets(message); // read input message from user

  printf("Enter key: ");
  scanf("%d", &key); // read encryption key from user

  for(i = 0; message[i] != '\0'; ++i){
    ch = message[i];

    // Encrypt uppercase characters
    if(ch >= 'A' && ch <= 'Z') {
      ch = ch + key;
      
      if(ch > 'Z'){
        ch = ch - 'Z' + 'A' - 1;
      }
      
      message[i] = ch;
    }

    // Encrypt lowercase characters
    else if(ch >= 'a' && ch <= 'z') {
      ch = ch + key;

      if(ch > 'z'){
        ch = ch - 'z' + 'a' - 1;
      }
      
      message[i] = ch;
    }
  }

  printf("Encrypted message: %s", message);

  return 0;
}