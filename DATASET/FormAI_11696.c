//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>

/* Calculate the 1's complement checksum of an array of bytes */
unsigned char ones_complement_checksum(unsigned char *bytes, int length) {
  int i;
  unsigned int sum = 0;
  
  /* Add up all the bytes in the array */
  for (i = 0; i < length; i++) {
    sum += bytes[i];
  }
  
  /* Fold the sum into a 16-bit integer */
  while (sum >> 16) {
    sum = (sum & 0xFFFF) + (sum >> 16);
  }
  
  /* Take the 1's complement of the result */
  sum = ~sum;
  
  return sum & 0xFF;
}

int main() {
  unsigned char bytes[] = {0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
  int length = sizeof(bytes) / sizeof(unsigned char);
  
  unsigned char checksum = ones_complement_checksum(bytes, length);
  
  printf("Checksum: 0x%02x\n", checksum);
  
  return 0;
}