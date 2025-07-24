//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>

#define POLYNOMIAL 0xEDB88320L
#define BUFFER_SIZE 1024

unsigned long crc_table[256];

// Function to create a CRC table
void crc_table_init() {
  int i, j;
  unsigned long crc_accum;

  for (i = 0; i < 256; i++) {
    crc_accum = (unsigned long)i;

    for (j = 0; j < 8; j++) {
      if (crc_accum & 1)
        crc_accum = (crc_accum >> 1) ^ POLYNOMIAL;
      else
        crc_accum >>= 1;
    }

    crc_table[i] = crc_accum;
  }
}

// Function to calculate the checksum
unsigned long calculate_checksum(unsigned char *data, int length) {
  unsigned long crc_accum = 0xFFFFFFFF;

  for (int i = 0; i < length; i++) {
    crc_accum = (crc_accum >> 8) ^ crc_table[(crc_accum & 0xFF) ^ data[i]];
  }

  return crc_accum ^ 0xFFFFFFFF;
}

int main() {
  crc_table_init();

  // Test with a sample string
  unsigned char buffer[BUFFER_SIZE] = "Hello, World!";

  unsigned long checksum = calculate_checksum(buffer, sizeof(buffer) - 1);

  printf("Checksum: %08X\n", checksum);

  return 0;
}