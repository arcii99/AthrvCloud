//FormAI DATASET v1.0 Category: QR code generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main() {
  char input_data[256] = "https://www.example.com"; // sample data
  int qr_version = 5; // QR code version (1-40)
  int qr_error_correction_level = QR_ECLEVEL_L; // error correction level (L, M, Q or H)
  
  QRcode *qr = QRcode_encodeString(input_data, 0, qr_error_correction_level, QR_MODE_8, 1); // generate QR code
  
  if (qr == NULL) {
    printf("Error: Failed to generate QR code.\n");
    exit(EXIT_FAILURE);
  }
  
  for (int i = 0; i < qr->width; i++) { // print QR code
    for (int j = 0; j < qr->width; j++) {
      if (qr->data[i * qr->width + j] & 1) {
        printf("█ "); // black pixel
      } else {
        printf("  "); // white pixel
      }
    }
    printf("\n");
  }
  
  QRcode_free(qr); // free QR code memory
  
  return 0;
}