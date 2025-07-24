//FormAI DATASET v1.0 Category: Modern Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>

/* Function declarations */
void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main()
{
   char message[100];
   int key;

   printf("Enter message to encrypt: ");
   fgets(message, sizeof(message), stdin);
   message[strcspn(message, "\n")] = 0;

   printf("Enter key (0-25): ");
   scanf("%d", &key);

   printf("\nOriginal message: %s\n", message);

   encrypt(message, key);
   printf("Encrypted message: %s\n", message);

   decrypt(message, key);
   printf("Decrypted message: %s\n", message);

   return 0;
}

/* Function to encrypt the message */
void encrypt(char *message, int key)
{
   char ch;
   int i;

   for(i = 0; message[i] != '\0'; ++i){
      ch = message[i];

      if(ch >= 'a' && ch <= 'z'){
         ch = ch + key;
         if(ch > 'z'){
            ch = ch - 'z' + 'a' - 1;
         }

         message[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z'){
         ch = ch + key;
         if(ch > 'Z'){
            ch = ch - 'Z' + 'A' - 1;
         }

         message[i] = ch;
      }
   }
}

/* Function to decrypt the message */
void decrypt(char *message, int key)
{
   char ch;
   int i;

   for(i = 0; message[i] != '\0'; ++i){
      ch = message[i];

      if(ch >= 'a' && ch <= 'z'){
         ch = ch - key;
         if(ch < 'a'){
            ch = ch + 'z' - 'a' + 1;
         }

         message[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z'){
         ch = ch - key;
         if(ch < 'A'){
            ch = ch + 'Z' - 'A' + 1;
         }

         message[i] = ch;
      }
   }
}