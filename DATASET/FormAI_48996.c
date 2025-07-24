//FormAI DATASET v1.0 Category: QR code reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QR_SIZE 21    // QR code size is constant for our example

bool isQRCode(char *code) {
  // Check if code is a valid QR code (e.g. starts with Q)
  if (code[0] == 'Q') {
    return true;
  }
  return false;
}

int readQRCode() {
  char *code = (char *) malloc(QR_SIZE * sizeof(char));   // Allocate memory for QR code
  printf("Place QR code in front of scanner: ");
  scanf("%s", code);

  if (!isQRCode(code)) {
    printf("Error: Invalid QR code!\n");
    free(code);   // Free dynamically allocated memory
    return -1;
  }

  // Print QR code information
  printf("QR code read successful!\n");
  printf("QR code: %s\n", code);

  free(code);   // Free dynamically allocated memory
  return 0;
}

int main() {
  // Continuously read QR codes
  while (1) {
    if (readQRCode() == -1) {
      continue;   // Repeat loop if invalid QR code is scanned
    }
  }

  return 0;
}