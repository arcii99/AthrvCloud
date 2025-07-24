//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {

   char message[100];
   char newMessage[100];
   int i, j, k;

   printf("Enter a message : ");
   scanf("%[^\n]", message);

   //Remove all vowels from the message
   for(i = 0; message[i]!='\0'; i++) {
      if(message[i] == 'a' || message[i] == 'e' || message[i] == 'i' ||
         message[i] == 'o' || message[i] == 'u' || message[i] == 'A' ||
         message[i] == 'E' || message[i] == 'I' || message[i] == 'O' ||
         message[i] == 'U'){
         continue;
      }
      newMessage[j++] = message[i];
   }

   newMessage[j] = '\0';

   printf("Message after removing vowels: %s\n", newMessage);

   //Check if the message is a palindrome
   k = strlen(newMessage)-1;

   for(i=0; i < strlen(newMessage); i++) {
      if(newMessage[i] != newMessage[k]) {
         printf("%s is not a palindrome\n", newMessage);
         return 0;
      }
      k--;
   }

   printf("%s is a palindrome\n", newMessage);

   return 0;
}