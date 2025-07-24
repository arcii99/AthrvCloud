//FormAI DATASET v1.0 Category: QR code generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generateQRCode(char *text, int size, char *fileName) {
  unsigned char *qrCodeData;
  QRcode *qrCode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
  qrCodeData = qrCode->data;
  
  FILE *fp;
  fp = fopen(fileName, "w+");
  
  // write QR code header
  fputs("P1\n", fp);
  fprintf(fp, "%d %d\n", qrCode->width, qrCode->width);

  // write QR code data
  int totalPixels = qrCode->width * qrCode->width;
  for(int i=0;i<totalPixels;i++) {
    fprintf(fp, "%d", (*qrCodeData & 1));
    qrCodeData++;
    if ((i+1) % qrCode->width == 0) {
      fprintf(fp, "\n");
    }
  }

  fclose(fp);
  QRcode_free(qrCode);
}

int main() {
  char *text = "https://www.example.com";
  char *fileName = "example.pbm";
  generateQRCode(text, strlen(text), fileName);
  printf("QR code generated successfully.\n");
  return 0;
}