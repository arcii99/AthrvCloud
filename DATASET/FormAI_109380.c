//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include<stdio.h>

int main() {
   char message[100];
   int i, checksum=0;

   printf("Enter message: ");
   scanf("%s",message);

   for(i=0; message[i]!='\0'; i++)
      checksum += message[i];

   printf("Checksum: %d",checksum);
   return 0;
}