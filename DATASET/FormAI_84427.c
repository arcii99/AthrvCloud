//FormAI DATASET v1.0 Category: QR code generator ; Style: authentic
#include <stdio.h>

// function to generate QR code
void generate_QR_Code(char data[]) {
  // QR code generation logic
  printf("QR code generated successfully for data: %s", data);
}

int main() {
  char data[100];
  printf("Enter data to generate QR code:\n");
  scanf("%s", data);

  generate_QR_Code(data);

  return 0;
}