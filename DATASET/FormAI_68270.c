//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
   unsigned char message[50];
   int len, i, sum = 0;

   printf("Enter the message to calculate Checksum:\n");
   fgets(message, sizeof(message), stdin);

   for(i=0;message[i]!='\0';i++) {
      sum += message[i];
   }

   printf("The calculated Checksum is: %x\n", sum);

   return 0;
}