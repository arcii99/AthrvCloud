//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>

/* Function to calculate 8-bit checksum */
unsigned char calculate_checksum(unsigned char *data, int length) {
  unsigned char checksum = 0;

  for(int i = 0; i < length; i++) {
    checksum += data[i];
  }

  return ~checksum; /* bitwise complement of checksum */
}

int main() {
  unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
  int length = sizeof(data) / sizeof(data[0]);
  unsigned char checksum = calculate_checksum(data, length);

  printf("Data: ");
  for(int i = 0; i < length; i++) {
    printf("0x%02x ", data[i]);
  }
  printf("\nChecksum: 0x%02x\n", checksum);

  return 0;
}