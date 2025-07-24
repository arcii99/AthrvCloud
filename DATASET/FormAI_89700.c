//FormAI DATASET v1.0 Category: QR code generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char *argv[])
{
  /* check if correct number of arguments are entered */
  if (argc != 3) {
    printf("Usage: %s [string] [filename.png]\n", argv[0]);
    return 1;
  }

  /* create QR code */
  QRcode *qr;
  qr = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

  /* check if QR code is valid */
  if (qr == NULL) {
    printf("Unable to create QR code\n");
    return 1;
  }

  /* create file to save QR code */
  FILE *file = fopen(argv[2], "wb");

  /* check if file is valid */
  if (file == NULL) {
    printf("Unable to create file\n");
    return 1;
  }

  /* write QR code to file */
  unsigned char *p, *q;
  p = q = qr->data;
  for(int y = 0; y < qr->width; y++) {
    for(int x = 0; x < qr->width; x++) {
      fputc((*p & 1) ? '1' : '0', file);
      p++;
    }
    fputc('\n', file);
  }

  /* cleanup */
  fclose(file);
  QRcode_free(qr);

  return 0;
}