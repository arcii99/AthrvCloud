//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

unsigned short calculateChecksum(char *data, int length);

int main() {
  char input[512];
  int i = 0;
  unsigned short checksum;
  
  printf("Enter the string to calculate the checksum: ");
  scanf("%s", input);
  
  checksum = calculateChecksum(input, strlen(input));
  
  printf("\nChecksum: %04X\n", checksum);
  
  return 0;
}

unsigned short calculateChecksum(char *data, int length) {
  int i;
  unsigned int sum = 0;
  unsigned short checksum;
  
  // Sum every 16-bit word in the data
  for (i = 0; i < length; i += 2) {
    sum += data[i] << 8;
    
    if (i + 1 < length) {
      sum += data[i+1];
    }
  }
  
  // Add the carry value to the sum
  while (sum >> 16) {
    sum = (sum & 0xFFFF) + (sum >> 16);
  }
  
  checksum = (unsigned short)~sum;
  
  return checksum;
}