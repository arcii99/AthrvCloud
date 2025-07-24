//FormAI DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char message[1000];
   printf("Enter your message here: ");
   fgets(message, sizeof(message), stdin);

   // Post-apocalyptic text processing:
   printf("\nYour message after post-apocalyptic text processing:\n");
   int i;
   for(i = 0; i < strlen(message); i++) {
      if(message[i] == 'o' || message[i] == 'O') {
         message[i] = '0';
      } else if(message[i] == 'e' || message[i] == 'E') {
         message[i] = '3';
      } else if(message[i] == 'a' || message[i] == 'A') {
         message[i] = '@';
      }
   }
   printf("%s", message);
   
   printf("\nDo you want to decode the message? (y/n): ");
   char answer;
   scanf("%c", &answer);

   if(answer == 'y' || answer == 'Y') {
      // Decoding the message:
      for(i = 0; i < strlen(message); i++) {
         if(message[i] == '0') {
            message[i] = 'o';
         } else if(message[i] == '3') {
            message[i] = 'e';
         } else if(message[i] == '@') {
            message[i] = 'a';
         }
      }
      printf("\nYour decoded message:\n");
      printf("%s", message);
   } else {
      printf("\nGoodbye!\n");
   }

   return 0;
}