//FormAI DATASET v1.0 Category: QR code generator ; Style: scalable
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generateQRCode(const char* data, int size) {
  QRcode *qr;
  unsigned char *qrcode; 
  int width, y, x;

  // Generating QR Code
  qr = QRcode_encodeString(data, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
  if (qr == NULL) {
    printf("Error in generating QR Code");
    exit(EXIT_FAILURE);
  }

  width = qr->width;
  qrcode = qr->data;

  // Printing QR Code
  for (y = 0; y < width; y++) {
    for (x = 0; x < width; x++) {
      if (*qrcode & 1) {
        printf("  ");
      }
      else {
        printf("██");
      }
      qrcode++;
    }
    printf("\n");
  }
}

int main(int argc, char** argv) {
  char data[100];
  int size;

  // Getting user input
  printf("Enter the data to be encoded in QR Code: ");
  scanf("%s", data);

  size = strlen(data);

  // Generating QR Code
  generateQRCode(data, size);

  return 0;
}