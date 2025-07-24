//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>

int main() {
  unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05}; //initialize data to be checked

  unsigned int sum = 0;
  for(int i=0; i<5; i++){
      sum += data[i];
  }

  unsigned char checksum = sum & 0xFF;  //apply bitmask to extract the last byte

  printf("Data to be checked:\n");
  for(int i=0; i<5; i++){
      printf("%02x ", data[i]);
  }

  printf("\n\nChecksum: %02x\n", checksum);

  return 0;
}