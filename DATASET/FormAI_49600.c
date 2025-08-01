//FormAI DATASET v1.0 Category: QR code generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
  int version = 4;
  int width = 64;
  int margin = 1;
  int dpi = 72;
  QRcode *qr;
  unsigned char *pixels;
  FILE *output;
  char *data = "This is a sample QR code generated by a visionary C program!";
  
  // Generate QR code
  qr = QRcode_encodeString(data, version, QR_ECLEVEL_L, QR_MODE_8, 1);
  
  // Allocate memory for pixel data
  pixels = (unsigned char *) calloc(qr->width * qr->width, sizeof(unsigned char));
  
  // Fill pixel data with QR code
  for (int i = 0; i < qr->width; i++) {
    for (int j = 0; j < qr->width; j++) {
      if (qr->data[i * qr->width + j] & 1) {
        pixels[i * qr->width + j] = 0;
      } else {
        pixels[i * qr->width + j] = 255;
      }
    }
  }
  
  // Write pixel data to file
  output = fopen("qrcode.pgm", "wb");
  fprintf(output, "P5\n%d %d\n%d\n", qr->width + margin * 2, qr->width + margin * 2, 255);
  for (int i = 0; i < qr->width + margin * 2; i++) {
    for (int j = 0; j < qr->width + margin * 2; j++) {
      if (i < margin || i >= qr->width + margin || j < margin || j >= qr->width + margin) {
        fputc(255, output);
      } else {
        fputc(pixels[(i - margin) * qr->width + (j - margin)], output);
      }
    }
  }
  fclose(output);
  
  // Free memory
  free(pixels);
  QRcode_free(qr);
  
  return 0;
}