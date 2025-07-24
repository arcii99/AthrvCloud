//FormAI DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
   char message[1000], keyword[100];
   int i, j, index = 0;

   printf("My love, please enter thy secret message:\n");
   fgets(message, sizeof(message), stdin);

   printf("My sweet, enter the secret keyword:\n");
   scanf("%s", keyword);

   for(i = 0; i < strlen(message); i++) {
      if(message[i] >= 'a' && message[i] <= 'z') {
         message[i] = ((message[i] - 'a') + keyword[index] - 'a') % 26 + 'a';
         index = (index + 1) % strlen(keyword);
      }
      else if(message[i] >= 'A' && message[i] <= 'Z') {
         message[i] = ((message[i] - 'A') + keyword[index] - 'a') % 26 + 'A';
         index = (index + 1) % strlen(keyword);
      }
   }

   printf("Hark, my love:\n%s", message);

   return 0;
}