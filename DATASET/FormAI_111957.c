//FormAI DATASET v1.0 Category: QR code generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main() {
  char data[256];
  printf("Please enter the data you want to encode: ");
  scanf("%s", data);

  QRcode* code = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
  if (code == NULL) {
    printf("An error occurred while generating the QR code.");
    return -1;
  }

  for (int i = 0; i < code->width; i++) {
    for (int j = 0; j < code->width; j++) {
      printf("%c", code->data[i * code->width + j] ? ' ' : '#');
    }
    printf("\n");
  }

  QRcode_free(code);

  return 0;
}