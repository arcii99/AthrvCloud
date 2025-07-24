//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>

int main() {
   char text[100];
   int i, j, k, ascii;

   printf("Enter a word or phrase: ");
   scanf("%[^\n]s", text);

   for (i = 0; text[i] != '\0'; i++) {
      ascii = (int) text[i];
      
      for (j = 0; j < ascii; j++) {
         printf("*");
      }

      printf("\n");

      if (i == 0 || i == strlen(text) - 1) {
         for (k = 1; k < ascii; k++) {
            printf("*");   
         }

         printf("\n");
      }
   }
   
   return 0;
}