//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
   unsigned char array[20] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,
                              0x0B,0x0C,0x0D,0x0E,0x0F,0x10};
   unsigned short checksum = 0;
   int i;

   for (i = 0; i < sizeof(array); i += 2)
      checksum += *(unsigned short *)&array[i];

   checksum = ~(checksum + (checksum >> 16));
   printf("The checksum is %04X\n", checksum);

   return 0;
}