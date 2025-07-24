//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Cryptic
#include <stdio.h>

int main() {
   char message[100];
   char watermark[] = "Watermark";
   int i;

   printf("Enter a message to have watermarked: ");
   gets(message);

   for (i = 0; i < strlen(watermark); i++) {
      printf("%c", watermark[i]);
   }

   printf("%s\n", message);

   return 0;
}