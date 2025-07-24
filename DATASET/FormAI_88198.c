//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>

int main() {
  unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
  unsigned char checksum = 0;
  int i;

  printf("Original Data: ");
  for (i = 0; i < sizeof(data); i++) {
    printf("%02x ", data[i]);
    checksum += data[i];
  }

  printf("\n");

  printf("Checksum: %02x\n", ~(checksum - 1));

  return 0;
}