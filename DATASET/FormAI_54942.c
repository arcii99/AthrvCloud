//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char message[100], ch;
  int length, i;
  
  printf("Enter a message to encrypt: ");
  fgets(message, 100, stdin);

  length = strlen(message) - 1;

  printf("Enter a key for encryption: ");
  scanf("%d", &i);

  for(i = 0; message[i] != '\0'; ++i){
    ch = message[i];

    if(ch >= 'a' && ch <= 'z'){
      ch = ch + i;

      if(ch > 'z'){
        ch = ch - 'z' + 'a' - 1;
      }

      message[i] = ch;
    }
    else if(ch >= 'A' && ch <= 'Z'){
      ch = ch + i;

      if(ch > 'Z'){
        ch = ch - 'Z' + 'A' - 1;
      }

      message[i] = ch;
    }
  }

  printf("Encrypted message: %s\n", message);

  return 0;
}