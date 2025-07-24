//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
   int data[100], checksum = 0, len;
   printf("Enter length of data: ");
   scanf("%d",&len);
   printf("Enter data: ");
   for(int i=0; i<len; i++) {
      scanf("%d",&data[i]);
   }
   for(int i=0;i<len;i++) {
      checksum += data[i];
   }
   checksum = ~(checksum % 256);

   printf("Checksum: %d\n", checksum);

   return 0;
}