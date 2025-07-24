//FormAI DATASET v1.0 Category: QR code generator ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <qrencode.h>

void generateQRCode(char* data, char* filename, int size) {
  QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
  int width = qrcode->width;

  FILE *fp = fopen(filename, "wb");
  for(int y = 0; y < width; y++) {
    for(int x = 0; x < width; x++) {
      if(qrcode->data[y*width+x] & 1) {
        fprintf(fp, "  ");
      } else {
        fprintf(fp, "\u2588\u2588");
      }
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
  QRcode_free(qrcode);
}

int main() {
  generateQRCode("Hello, World!", "hello-world-qrcode.txt", 20);
  return 0;
}