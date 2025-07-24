//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int calculateChecksum(int* data, int length) {
  int checksum = 0;
  for (int i = 0; i < length; i++) {
    checksum += data[i];
  }
  return checksum;
}

int main() {
  //initialize data array
  int data[] = {1, 2, 3, 4, 5};
  //get length of data array
  int length = sizeof(data) / sizeof(data[0]);
  //calculate checksum
  int checksum = calculateChecksum(data, length);
  //print checksum
  printf("The checksum is: %d\n", checksum);
  return 0;
}