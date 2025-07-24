//FormAI DATASET v1.0 Category: QR code reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define QR_CODE_SIZE 21

int main() {

  // Configurable QR code data
  uint8_t qrData[QR_CODE_SIZE] = {0x17,0x16,0x05,0x12,0xF2,0xDD,0xA7,0x0E,0x1C,0x17,0x16,0x05,0x12,0xF2,0xDD,0xA7,0x0E,0x1C,0x17,0x16,0x05};
  
  // Function to read a QR code pixel and return its value
  uint8_t readQRPixel(uint8_t *qrData, uint8_t x, uint8_t y) {
      return qrData[y * 21 + x];
  }

  // Print the QR code matrix
  printf("QR Code Matrix:\n");
  for (int i = 0; i < QR_CODE_SIZE; i++) {
      for (int j = 0; j < QR_CODE_SIZE; j++) {
          uint8_t pixelVal = readQRPixel(qrData, i, j);
          if (pixelVal == 1) {
              printf("# ");
          } else {
              printf("  ");
          }
      }
      printf("\n");
  }

  return 0;
}