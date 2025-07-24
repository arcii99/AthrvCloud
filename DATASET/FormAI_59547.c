//FormAI DATASET v1.0 Category: QR code generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
  // prompt user for input
  char input[256];
  printf("Enter the data to be encoded as QR code: ");
  scanf("%255s", input);

  // encode as QR code
  QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

  // print QR code as ASCII art
  int width = qrcode->width;
  for (int y = 0; y < width; y++) {
    for (int x = 0; x < width; x++) {
      int index = y * width + x;
      bool bit = qrcode->data[index] & 1;
      putchar(bit ? ' ' : '#');
    }
    putchar('\n');
  }
  putchar('\n');

  // free memory used for QR code
  QRcode_free(qrcode);

  return 0;
}