//FormAI DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>

int main() {
   char str[100], encrypted_str[100], decrypted_str[100];
   int key, i;
   
   printf("Enter a string: ");
   gets(str);
   
   printf("Enter a key: ");
   scanf("%d", &key);
   
   // Encryption
   for (i = 0; str[i] != '\0'; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
         encrypted_str[i] = ((str[i] - 'a' + key) % 26) + 'a';
      }
      else if (str[i] >= 'A' && str[i] <= 'Z') {
         encrypted_str[i] = ((str[i] - 'A' + key) % 26) + 'A';
      }
   }
   
   encrypted_str[i] = '\0';
   
   printf("Encrypted string: %s\n", encrypted_str);
   
   // Decryption
   for (i = 0; encrypted_str[i] != '\0'; i++) {
      if (encrypted_str[i] >= 'a' && encrypted_str[i] <= 'z') {
         decrypted_str[i] = (((encrypted_str[i] - 'a') - key + 26) % 26) + 'a';
      }
      else if (encrypted_str[i] >= 'A' && encrypted_str[i] <= 'Z') {
         decrypted_str[i] = (((encrypted_str[i] - 'A') - key + 26) % 26) + 'A';
      }
   }
   
   decrypted_str[i] = '\0';
   
   printf("Decrypted string: %s\n", decrypted_str);

   return 0;
}