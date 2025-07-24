//FormAI DATASET v1.0 Category: QR code generator ; Style: happy
#include <qrencode.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  QRcode *qrcode;

  // Create QR code from input string
  qrcode = QRcode_encodeString("Hello, world!", 0, QR_ECLEVEL_L, QR_MODE_8, 1);

  // Print generated QR code
  for (int y = 0; y < qrcode->width; y++) {
    for (int x = 0; x < qrcode->width; x++) {
      printf(qrcode->data[y*qrcode->width+x] ? "\u2588\u2588" : "  ");
    }
    printf("\n");
  }

  // Cleanup QR code memory
  QRcode_free(qrcode);

  return 0;
}