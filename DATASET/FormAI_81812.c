//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], int key);
void decrypt(char message[], int key);

int main()
{
   char message[1000];
   int key;
   
   printf("Enter message: ");
   fgets(message, 1000, stdin);
   
   printf("Enter key: ");
   scanf("%d", &key);
    
   encrypt(message, key);
   printf("Encrypted message: %s\n", message);
   
   decrypt(message, key);
   printf("Decrypted message: %s\n", message);
   
   return 0;
}

void encrypt(char message[], int key)
{
    int len = strlen(message);
    for(int i = 0; i < len; i++)
    {
        message[i] = (char)(message[i] + key);
    }
}

void decrypt(char message[], int key)
{
    int len = strlen(message);
    for(int i = 0; i < len; i++)
    {
        message[i] = (char)(message[i] - key);
    }
}