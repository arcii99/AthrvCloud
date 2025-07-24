//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: synchronous
#include <stdio.h>

unsigned short calculateChecksum(unsigned char *data, unsigned int length) {
  unsigned int i;
  unsigned short sum = 0;
  unsigned short headerSize = 8; // assuming 8 byte header

  // sum header bytes
  for (i = 0; i < headerSize; i+=2) {
    sum += (data[i] << 8) | data[i+1];
  }

  // sum data bytes
  for (i = headerSize; i < length; i+=2) {
    sum += (data[i] << 8) | data[i+1];
  }

  // fold in carry bits
  while (sum >> 16) {
    sum = (sum & 0xFFFF) + (sum >> 16);
  }

  return ~sum; // return ones-complement of sum
}

void printData(unsigned char *data, unsigned int length) {
  unsigned int i;
  for (i = 0; i < length; i++) {
    printf("0x%02X ", data[i]);
    if ((i+1) % 16 == 0) printf("\n"); // new line every 16 bytes
  }
  printf("\n");
}

int main() {
  unsigned char data[] = {0x45, 0x00, 0x00, 0x73, 0x2B, 0x7E, 0x40, 0x00, 0x40, 0x06, 0x5C, 0xD6, 0xC0, 0xA8, 0x01, 0x0B, 0xC0, 0xA8, 0x01, 0x64, 0xD5, 0x37, 0x00, 0x50, 0xCE, 0x07, 0x79, 0x00, 0x00, 0x00, 0x00, 0x80, 0x02, 0xFF, 0xFF, 0xAA, 0xAA, 0x00, 0x00, 0x02, 0x04, 0x05, 0xB4, 0x04, 0x02, 0x08, 0x0A, 0x12, 0xCC, 0x50, 0x7D, 0x00, 0x00, 0x00, 0x00};

  unsigned int length = sizeof(data);
  printf("Data:\n");
  printData(data, length);

  unsigned short checksum = calculateChecksum(data, length);
  printf("Checksum: 0x%04X\n", checksum);

  return 0;
}