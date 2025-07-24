//FormAI DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
   char love[] = "Romeo loves Juliet";
   int i;

   for(i = 0; i < strlen(love); i++) {
      printf("%c\n", love[i]);
   }

   char hate[] = "Romeo hates Python";
   int j;

   for(j = 0; j < strlen(hate); j++) {
      printf("%c\n", hate[j]);
   }

   int forever = 1;

   while(forever) {
      printf("Romeo and Juliet are together!\n");
   }

   return 0;
}