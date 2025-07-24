//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {

   char message[100];
   int count = 0, i;

   printf("Please enter your message: ");
   gets(message);

   for (i = 0; message[i] != '\0'; i++) {
      if (message[i] == 's' && message[i+1] == 'p' && message[i+2] == 'a' && message[i+3] == 'm') {
         count++;
         printf("SPAM Detected! ");
         break;
      }
   }

   if (count == 0) {
      printf("Your message is not spam.\n");
   }
   
   printf("Cleaning message of spam...");
   for(i=0;i<strlen(message);i++) {
       if ((message[i] != 's' && message[i] != 'S') || (message[i+1] != 'p' && message[i+1] != 'P') || 
       (message[i+2] != 'a' && message[i+2] != 'A') || (message[i+3] != 'm' && message[i+3] != 'M')) {
           printf("%c", message[i]); 
       } else {
           i += 3;
       }
   }
   printf("\n");
   
   printf("Final cleaned message: \n%s\n", message);

   return 0;
}