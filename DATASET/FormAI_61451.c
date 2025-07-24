//FormAI DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT 100

void encrypt(char* str);

int main(void) {
   char message[MAX_LIMIT];
   
   printf("Enter a message to encrypt: ");
   fgets(message, MAX_LIMIT, stdin);

   // Removing the '\n' character from the input 
    char *pos;
    if ((pos = strchr(message, '\n')) != NULL)
        *pos = '\0';

   // Calling the encryption function
   encrypt(message);

   printf("The encrypted message is: %s\n", message);

   return 0;
}

void encrypt(char* str) {
   int length = strlen(str);

   for(int i=0; i<length; i++) {
      if(str[i] >= 'a' && str[i] <= 'z') {
         str[i] = 'z' - (str[i] - 'a');
      } else if(str[i] >= 'A' && str[i] <= 'Z') {
         str[i] = 'Z' - (str[i] - 'A');
      }
   }
}