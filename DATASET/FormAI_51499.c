//FormAI DATASET v1.0 Category: QR code generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <qrencode.h>

#define MAX_INPUT_SIZE 100

int main() {
  char input[MAX_INPUT_SIZE];
  printf("Enter text to encode: ");
  fgets(input, MAX_INPUT_SIZE, stdin);
  input[strcspn(input, "\n")] = 0; // remove newline character at end of input string
  
  QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_M, QR_MODE_8, 1);
  
  if (qrcode == NULL) {
    printf("Error: Failed to generate QR code\n");
    exit(EXIT_FAILURE);
  }
  
  // print QR code to terminal
  for (int i = 0; i < qrcode->width; i++) {
    for (int j = 0; j < qrcode->width; j++) {
      if (qrcode->data[i * qrcode->width + j] & 1) {
        printf("  ");
      } else {
        printf("\u2588\u2588"); // unicode block character
      }
    }
    printf("\n");
  }
  
  QRcode_free(qrcode);
  
  return 0;
}