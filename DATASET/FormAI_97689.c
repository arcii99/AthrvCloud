//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
   char message[20];
   printf("Enter a message: ");
   scanf("%s", message);

   int i, j;
   for(i=0; i<20; i++) {
      if(message[i] == '\0') break;
      for(j=0; j<8; j++) {
         if((message[i] >> j) & 0x01) printf("@");
         else printf(".");
      }
      printf("\n");
   }

   return 0;
}