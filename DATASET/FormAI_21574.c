//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: all-encompassing
#include <stdio.h>

// Function to calculate checksum
unsigned char calculate_checksum(char* data, int len) 
{
  unsigned int sum = 0;
  unsigned char checksum;
  
  // Loop through data and sum up the bytes
  for (int i = 0; i < len; i++) 
  {
    sum += data[i];
  }
  
  // Get the 1's complement of the sum
  sum = ~(sum & 0xFF);
  
  // Get the least significant byte of the 1's complement
  checksum = sum & 0xFF;
  
  return checksum;
}

int main() 
{
  char data[] = {0xA6, 0x00, 0x01, 0x13, 0x25};
  int len = sizeof(data);
  
  unsigned char checksum = calculate_checksum(data, len);
  
  printf("Checksum of the data is: 0x%02X\n", checksum);
  
  return 0;
}