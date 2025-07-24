//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: dynamic
#include <stdio.h>

// Computes the checksum
unsigned char compute_checksum(unsigned char *data, int length) {
  unsigned char checksum = 0x00;
  for (int i = 0; i < length; i++) {
    checksum ^= data[i];
  }
  return checksum;
}

int main() {
  unsigned char input_data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
  int input_length = sizeof(input_data) / sizeof(input_data[0]);
  unsigned char checksum = compute_checksum(input_data, input_length);

  printf("Input Data: ");
  for (int i = 0; i < input_length; i++) {
    printf("%02X ", input_data[i]);
  }
  printf("\n");

  printf("Checksum: %02X\n", checksum);

  return 0;
}