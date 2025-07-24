//FormAI DATASET v1.0 Category: QR code reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of a QR code string
#define MAX_QR_CODE_LEN 100

int main(void) {
  // Initialize variables
  char qrCode[MAX_QR_CODE_LEN];
  bool isValidQRCode = false;
  
  // Prompt the user to input the QR code
  printf("Please scan the QR code: ");
  scanf("%s", qrCode);

  // Validate the QR code
  if (strlen(qrCode) == 25) {
    int startIndex = 0;
    
    // Check if the QR code starts with "C00L"
    if (strncmp(qrCode, "C00L", 4) == 0) {
      startIndex = 4;
      isValidQRCode = true;
    }
    
    // Extract the data from the QR code
    if (isValidQRCode) {
        char data[MAX_QR_CODE_LEN];
        strcpy(data, "");
        strncat(data, qrCode + startIndex + 1, qrCode[startIndex] - '0');
        printf("QR code data: %s\n", data);
    }
  }
  
  // Output the result to the user
  if (!isValidQRCode) {
    printf("Invalid QR code!\n");
  }
  
  return 0;
}