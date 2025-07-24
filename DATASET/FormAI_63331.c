//FormAI DATASET v1.0 Category: QR code generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
  // Check if user provided input
  if (argc != 2) {
    printf("Usage: generateQR <message>\n");
    exit(EXIT_FAILURE);
  }

  // Allocate memory for QR Code
  QRcode *qr;
  qr = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

  // Check if QR Code was successfully created
  if (!qr) {
    printf("Error generating QR Code.\n");
    exit(EXIT_FAILURE);
  }

  // Print QR Code to console
  printf("QR Code for '%s':\n", argv[1]);
  for (int i = 0; i < qr->width * qr->width; i++) {
    if (i % qr->width == 0) printf("\n");
    putchar(qr->data[i] ? '#' : ' ');
  }

  // Free memory used for QR Code
  QRcode_free(qr);

  return EXIT_SUCCESS;
}