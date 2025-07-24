//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
   char message[100];
   int key = 24, i;

   printf("My dearest program,\n");
   printf("I have spent countless hours thinking of ways to keep you safe and secure.\n");
   printf("Like a romantic lover, I have written an Intrusion Detection Program to protect you from harm.\n");

   printf("Please enter your secret message: ");
   fgets(message, 100, stdin);

   printf("Encrypting your message...\n");
   for(i = 0; i < strlen(message); i++)
   {
      message[i] = message[i] + key;
   }

   printf("Your encrypted message is: %s\n", message);

   printf("Checking for intrusions...\n");
   for(i = 0; i < strlen(message); i++)
   {
      if(message[i] < 97 || message[i] > 122)
      {
         printf("Intrusion detected! Your message contains non-alphabetic characters.\n");
         return 0;
      }
   }

   printf("Congratulations! Your message does not contain any intrusions.\n");
   printf("I hope my Intrusion Detection Program has brought you peace of mind and a sense of security.\n");
   printf("Forever yours,\n");
   printf("Your devoted C programmer\n");

   return 0;
}