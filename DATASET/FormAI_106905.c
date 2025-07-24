//FormAI DATASET v1.0 Category: QR code reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h> 

#define MAX_QR_CODE_LENGTH 500

int main(void) {
  char qrCode[MAX_QR_CODE_LENGTH];
  char qrCodePrefix[] = "QRCode:";
  bool codeMatched = false;

  printf("Please scan a QR code: \n");
  scanf("%s", qrCode);

  // Validating QR code prefix
  if (strlen(qrCode) < strlen(qrCodePrefix) ||
      strncmp(qrCode, qrCodePrefix, strlen(qrCodePrefix)) != 0) {
    printf("Invalid QR code.\n");
    exit(1);
  }

  // Extracting code content
  char* codeContent = qrCode + strlen(qrCodePrefix);

  // Reading QR code content as integer
  int code = strtol(codeContent, NULL, 10);

  // Displaying the QR code content
  printf("QR code content: %d\n", code);

  return 0;
}