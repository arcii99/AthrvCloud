//FormAI DATASET v1.0 Category: QR code reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define QR_CODE_SIZE 25

bool isQRCodeValid(char *qrCode) {
  if(strlen(qrCode) != QR_CODE_SIZE)
    return false;

  for(int i = 0; i < QR_CODE_SIZE; i++) {
    if(!isdigit(qrCode[i]))
      return false;
  }

  return true;
}

void readQRCode(char *qrCode) {
  printf("Please scan the QR code: ");
  scanf("%s", qrCode);

  while(!isQRCodeValid(qrCode)) {
    printf("Invalid QR code, please scan again: ");
    scanf("%s", qrCode);
  }
}

void processQRCode(char *qrCode) {
  // Your code here to process the QR code
  printf("QR code %s processed successfully!\n", qrCode);
}

int main() {
  char *qrCode = malloc(sizeof(char) * QR_CODE_SIZE + 1);

  readQRCode(qrCode);
  processQRCode(qrCode);

  free(qrCode);

  return 0;
}