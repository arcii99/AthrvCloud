//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: careful
#include <stdio.h>

int main() {
  unsigned char data[10] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
  unsigned char checksum = 0;

  // Calculate checksum
  for(int i = 0; i < 10; i++) {
    checksum ^= data[i];
  }

  // Print checksum
  printf("Checksum is: %X\n", checksum);

  return 0;
}