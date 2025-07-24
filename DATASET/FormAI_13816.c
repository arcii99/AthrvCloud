//FormAI DATASET v1.0 Category: QR code generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main() {
  //set default values
  int size = 5;
  int margin = 2;
  char data[] = "Hello World!";

  //ask user for input
  printf("Enter data to encode: ");
  fgets(data, sizeof(data), stdin);
  data[strlen(data) - 1] = '\0';
  printf("Enter size of QR code (default is 5): ");
  scanf("%d", &size);
  printf("Enter margin size (default is 2): ");
  scanf("%d", &margin);
  
  //create QR code
  QRcode *qr;
  qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

  //print QR code
  int width = qr->width;
  char *qr_data = qr->data;
  for (int y = 0; y < width; y++) {
    for (int x = 0; x < width; x++) {
      if (*qr_data & 1) {
        printf("##");
      } else {
        printf("  ");
      }
      qr_data++;
    }
    printf("\n");
  }

  //clean up
  QRcode_free(qr);
  return 0;
}