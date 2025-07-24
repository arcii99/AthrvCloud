//FormAI DATASET v1.0 Category: QR code generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
  char *text = "Hello, World!"; // default text to encode

  // override the default text if user provides an argument
  if (argc > 1) {
    text = argv[1];
  }

  QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_M, QR_MODE_8, 1);

  // check for errors when generating QR code
  if (qrcode == NULL) {
    fprintf(stderr, "QR code generation failed.\n");
    return EXIT_FAILURE;
  }

  // print out QR code as ASCII art
  for (int i = 0; i < qrcode->width + 4; i++) {
    putchar('_');
  }
  putchar('\n');

  for (int i = 0; i < qrcode->width; i++) {
    putchar('|');
    for (int j = 0; j < qrcode->width; j++) {
      putchar(qrcode->data[i*qrcode->width+j]&1 ? ' ' : '#');
    }
    puts(" |");
  }

  for (int i = 0; i < qrcode->width + 4; i++) {
    putchar('_');
  }
  putchar('\n');

  QRcode_free(qrcode);

  return EXIT_SUCCESS;
}