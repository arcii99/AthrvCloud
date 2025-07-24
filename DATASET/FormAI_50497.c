//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>

int calc_checksum(char* data, int data_len) {
  int checksum = 0;
  int i;
  
  // calculate the checksum by iterating over the data
  for (i = 0; i < data_len; i++) {
    checksum += data[i];
  }
  
  // cap the checksum at 255
  checksum %= 256;
  
  // invert the checksum to get the final value
  checksum = 255 - checksum;
  
  return checksum;
}

int main() {
  char data[100];
  int data_len;
  
  // get the user input
  printf("Enter the data to calculate the checksum for: ");
  scanf("%s", data);
  
  // calculate the checksum
  data_len = strlen(data);
  int checksum = calc_checksum(data, data_len);
  
  // print the checksum
  printf("The checksum of %s is %d\n", data, checksum);
  
  return 0;
}