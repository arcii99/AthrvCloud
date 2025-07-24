//FormAI DATASET v1.0 Category: QR code reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1000

int main() {
  char qr_code[MAX_STRING_SIZE];
  printf("Please enter your QR code: ");
  fgets(qr_code, MAX_STRING_SIZE, stdin);
  qr_code[strcspn(qr_code, "\n")] = 0;

  // Check if input is valid QR code
  int num_chars = strlen(qr_code);
  if (num_chars >= 21 && num_chars <= 25) {
    char* code_type = strtok(qr_code, "|");
    char* code_data = strtok(NULL, "");

    // Check if code type is valid
    if (strcmp(code_type, "CQR") == 0) {
      printf("Code type: CQR\nCode data: %s\n", code_data);
    } else {
      printf("Invalid code type. Expected CQR, got %s.", code_type);
    }
  } else {
    printf("Invalid QR code. Please enter a valid CQR code.");
  }
  return 0;
}