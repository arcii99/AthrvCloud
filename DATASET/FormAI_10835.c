//FormAI DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>

int main() {
   // Define the string to be encrypted
   char input_str[] = "example";
   // Define the encryption key
   int key = 4;
   // Loop through each character in the input string
   int i;
   for(i = 0; input_str[i] != '\0'; i++) {
      // Shift each character by the encryption key
      if(input_str[i] >= 'a' && input_str[i] <= 'z') {
         input_str[i] = (char)(((input_str[i] - 'a' + key) % 26) + 'a');
      }
      else if(input_str[i] >= 'A' && input_str[i] <= 'Z') {
         input_str[i] = (char)(((input_str[i] - 'A' + key) % 26) + 'A');
      }
   }
   // Print the encrypted string
   printf("Encrypted string: %s\n", input_str);
   
   // Reverse the encryption
   for(i = 0; input_str[i] != '\0'; i++) {
      // Shift each character in the opposite direction of the encryption key
      if(input_str[i] >= 'a' && input_str[i] <= 'z') {
         input_str[i] = (char)(((input_str[i] - 'a' - key + 26) % 26) + 'a');
      }
      else if(input_str[i] >= 'A' && input_str[i] <= 'Z') {
         input_str[i] = (char)(((input_str[i] - 'A' - key + 26) % 26) + 'A');
      }
   }
   // Print the decrypted string
   printf("Decrypted string: %s\n", input_str);

   return 0;
}