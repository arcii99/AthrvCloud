//FormAI DATASET v1.0 Category: Encryption ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *message, int key);

int main()
{
   char message[100];
   int key;

   printf("Enter a message to encrypt: ");
   fgets(message, 100, stdin);

   printf("Enter a key value: ");
   scanf("%d", &key);

   encrypt(message, key);

   printf("Encrypted message: %s", message);

   return 0;
}

void encrypt(char *message, int key)
{
   while (*message != '\0') {
      *message = *message + key;
      message++;
   }
}