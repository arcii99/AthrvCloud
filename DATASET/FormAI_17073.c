//FormAI DATASET v1.0 Category: QR code generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
  // check if command line arguments are provided
  if(argc < 2) {
    printf("Usage: %s <content to encode>\n", argv[0]);
    return 1;
  }
  
  // create QR code object and encode provided content
  QRcode *qrcode;
  char *content = argv[1];
  qrcode = QRcode_encodeString(content, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);

  // check if encoding was successful
  if(qrcode == NULL) {
    printf("Could not encode content.\n");
    return 1;
  }

  // print QR code to console
  int module_size = 2;
  for(int i = 0; i < qrcode->width; i++) {
    for(int j = 0; j < qrcode->width; j++) {
      int val = qrcode->data[i*qrcode->width+j];
      if(val > 0) {
        printf("##");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // free allocated memory
  QRcode_free(qrcode);

  return 0;
}