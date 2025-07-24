//FormAI DATASET v1.0 Category: QR code reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct QRCode {
  char* data;
  int version;
  int mode;
  int size;
  char* errorCorrection;
  bool isValid;
} QRCode;

QRCode parseQRCode(char* input) {
  QRCode result;
  result.data = NULL;
  result.version = -1;
  result.mode = -1;
  result.size = -1;
  result.errorCorrection = NULL;
  result.isValid = false;

  // TODO: Implement QR code parsing logic
  // ...

  return result;
}

void printQRCode(QRCode code) {
  printf("\nQR Code Information\n");
  printf("===================\n");
  printf("Data: %s\n", code.data);
  printf("Version: %d\n", code.version);
  printf("Mode: %d\n", code.mode);
  printf("Size: %d\n", code.size);
  printf("Error Correction: %s\n", code.errorCorrection);
  printf("Is Valid: %s\n", code.isValid ? "Yes" : "No");
}

int main() {
  printf("Enter a QR code to parse: ");

  char input[100];
  fgets(input, 100, stdin);

  // Remove newline character from input
  input[strcspn(input, "\n")] = 0;

  QRCode code = parseQRCode(input);
  printQRCode(code);

  return 0;
}