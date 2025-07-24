//FormAI DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>

int main() {
   int original[100], encoded[100], secret[100];
   int i, j, key;

   printf("Enter the secret message: ");
   for(i = 0; i < 100; i++) {
      scanf("%d", &secret[i]);
      if(secret[i] == -1) {
         break;
      }
   }

   printf("Enter the key: ");
   scanf("%d", &key);

   for(i = 0; i < 100; i++) {
      original[i] = secret[i];
      encoded[i] = secret[i] ^ key;
   }

   printf("Original message: ");
   for(i = 0; i < 100; i++) {
      if(original[i] == -1) {
         break;
      }
      printf("%c", original[i]);
   }

   printf("\nEncoded message: ");
   for(i = 0; i < 100; i++) {
      if(encoded[i] == -1) {
         break;
      }
      printf("%c", encoded[i]);
   }

   printf("\nDecoded message: ");
   for(i = 0; i < 100; i++) {
      if(encoded[i] == -1) {
         break;
      }
      printf("%c", encoded[i] ^ key);
   }

   return 0;
}