//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: expert-level
#include <stdio.h>

unsigned short calculate_checksum(unsigned char data[], int length);

int main() {
  unsigned char data[] = {0x01, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // example data
  int length = sizeof(data); // calculate length of data array
  unsigned short checksum = calculate_checksum(data, length); // calculate checksum 
  printf("Calculated checksum: 0x%X\n", checksum); // display checksum in hexadecimal format
  return 0;
}

unsigned short calculate_checksum(unsigned char data[], int length) {
  unsigned long sum = 0;
  int i;

  // sum data in 16-bit chunks
  for (i = 0; i < length-1; i+=2) {
    sum += ((unsigned short)data[i] << 8) + (unsigned short)data[i+1];
  }
  
  // handle odd-length data
  if (length % 2 == 1) {
    sum += ((unsigned short)data[length-1] << 8);
  }
  
  // fold 32-bit sum into 16-bit
  while (sum >> 16) {
    sum = (sum & 0xFFFF) + (sum >> 16);
  }

  // invert bits and return checksum
  return (unsigned short)(~sum);
}