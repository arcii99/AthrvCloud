//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
   unsigned char buffer[1024];
   unsigned int checksum = 0;
   int len = 0;
   printf("Enter the string to calculate the checksum: ");
   fgets(buffer, sizeof(buffer), stdin);
   while (buffer[len] != '\n') {
      checksum += buffer[len];
      len++;
   }
   printf("The checksum is: %u\n", checksum);
   return 0;
}