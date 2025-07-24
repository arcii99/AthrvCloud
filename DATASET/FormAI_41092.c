//FormAI DATASET v1.0 Category: QR code generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the QR code structure
typedef struct QRCode {
  char *data;
  int size;
} QRCode;

// Generate the QR code based on the input data
QRCode generate_qr_code(char *data) {
  QRCode code;
  code.size = strlen(data) + 2;
  code.data = (char *)malloc(code.size * sizeof(char));

  // Start and end markers
  char start_marker = '#';
  char end_marker = '*';

  // Add the start marker to the beginning
  code.data[0] = start_marker;

  // Add the input data to the code
  for (int i = 0; i < strlen(data); i++) {
    code.data[i+1] = data[i];
  }

  // Add the end marker to the end
  code.data[code.size-1] = end_marker;

  return code;
}

int main() {
  char input[100];
  printf("Enter data to generate QR Code: ");
  scanf("%s", input);

  QRCode code = generate_qr_code(input);

  printf("\nGenerated QR Code:\n");
  printf("%s\n", code.data);

  return 0;
}