//FormAI DATASET v1.0 Category: QR code generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

  // Check if user inputs are correct
  if(argc != 2) {
    printf("Usage: %s <text>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Set up QR code parameters
  QRcode *qr;
  QRinput *input;
  QRencodeMode mode = QR_MODE_8;
  int version = 0;
  QRecLevel level = QR_ECLEVEL_L;

  // Convert text to UTF-8
  unsigned char *text = (unsigned char *) argv[1];

  // Create input object
  input = QRinput_new2(strlen((char*)text), mode);
  QRinput_append(input, QR_MODE_8, strlen((char*)text), text);

  // Create QR code
  qr = QRcode_encodeInput(input);
  printf("QR code version: %d\n", qr->version);

  // Print QR code
  int x, y;
  for(y=0; y<qr->width; y++) {
    for(x=0; x<qr->width; x++) {
      if(qr->data[y*qr->width+x] & 1) {
        putchar('#');
      } else {
        putchar(' ');
      }
    }
    putchar('\n');
  }

  // Free memory
  QRcode_free(qr);
  QRinput_free(input);

  return EXIT_SUCCESS;
}