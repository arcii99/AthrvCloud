//FormAI DATASET v1.0 Category: Modern Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main()
{
   // Generate random key and plaintext
   char key[100], str[100];
   int i, j;

   printf("Enter the key: ");
   fgets(key, 100, stdin);

   printf("Enter the plaintext: ");
   fgets(str, 100, stdin);

   // Encrypt the plaintext with the key
   int keyLength = strlen(key) - 1;
   int strLength = strlen(str) - 1;

   for(i = 0, j = 0; i < strLength; ++i, ++j)
   {
      if(j == keyLength)
         j = 0;

      str[i] = ((str[i] + key[j] - 2 * 'a') % 26) + 'a';
   }

   printf("Encrypted text: %s", str);

   // Decrypt the ciphertext with the key
   for(i = 0, j = 0; i < strLength; ++i, ++j)
   {
      if(j == keyLength)
         j = 0;

      str[i] = ((str[i] - key[j] + 26) % 26) + 'a';
   }

   printf("\nDecrypted text: %s", str);

   return 0;
}