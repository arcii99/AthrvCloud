//FormAI DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char message[100], ch;
   int i, key;

   printf("Enter a message to encrypt: ");
   gets(message);

   printf("Enter key: ");
   scanf("%d", &key);

   //encrypting the message
   for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        //encrypt lower case letters
        if(ch >= 'a' && ch <= 'z'){
            ch = (ch + key - 'a') % 26 + 'a';
            message[i] = ch;
        }

        //encrypt upper case letters
        else if(ch >= 'A' && ch <= 'Z'){
            ch = (ch + key - 'A') % 26 + 'A';
            message[i] = ch;
        }
   }

   printf("The encrypted message is: %s", message);

   return 0;
}