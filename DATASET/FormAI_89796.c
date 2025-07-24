//FormAI DATASET v1.0 Category: QR code generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define MAX_STRING_LENGTH 100

int main(int argc, char *argv[]) {

  // Initialize the QRcode struct and set its version and error correction level
  QRcode *qrcode = NULL;
  int version = 10;
  QRecLevel level = QR_ECLEVEL_L;

  // Create a buffer to hold the data, with a maximum size of MAX_STRING_LENGTH
  char data_buf[MAX_STRING_LENGTH];
  memset(data_buf, '\0', MAX_STRING_LENGTH);

  // Prompt the user for input data
  printf("Enter data to encode as QR code: ");
  fgets(data_buf, MAX_STRING_LENGTH, stdin);
  strtok(data_buf, "\n"); // remove trailing newline character

  // Generate the QR code
  qrcode = QRcode_encodeString(data_buf, 0, level, QR_MODE_8, 1);
  if (qrcode == NULL) {
    printf("QR code generation failed!\n");
    return 0;
  }

  // Print the QR code to the console
  int width = qrcode->width;
  for (int y = 0; y < width; y++) {
    for (int x = 0; x < width; x++) {
      char symbol = (qrcode->data[y * width + x] & 0x01) ? '#' : ' ';
      printf("%c%c", symbol, symbol); // print each symbol twice for correct aspect ratio
    }
    printf("\n");
  }

  // Free the resources allocated for the QR code
  QRcode_free(qrcode);

  return 0;
}