//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>

void embedWatermark(int data[], int watermark[], int size) {
  for(int i = 0; i < size; i++) {
    if(watermark[i] == 1) {
      data[i] |= 1; // Set the least significant bit to 1
    } else {
      data[i] &= ~1; // Set the least significant bit to 0
    }
  }
}

int extractWatermark(int data[], int size) {
  int watermark = 0;
  for(int i = 0; i < size; i++) {
    if((data[i] & 1) == 1) {
      watermark |= 1; // Set the corresponding bit to 1
    } else {
      watermark &= ~1; // Set the corresponding bit to 0
    }
    watermark <<= 1; // Shift the watermark to the left by 1 bit
  }
  return watermark;
}

int main() {
  int data[8] = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0}; // Arbitrary data
  int watermark[3] = {1, 0, 1}; // Arbitrary watermark
  int size = sizeof(data) / sizeof(data[0]);
  printf("Data before embedding watermark:\n");
  for(int i = 0; i < size; i++) {
    printf("%02x ", data[i]);
  }
  printf("\n");
  embedWatermark(data, watermark, size);
  printf("Data after embedding watermark:\n");
  for(int i = 0; i < size; i++) {
    printf("%02x ", data[i]);
  }
  printf("\n");
  int extractedWatermark = extractWatermark(data, size);
  printf("Extracted watermark: %d\n", extractedWatermark);
  return 0;
}