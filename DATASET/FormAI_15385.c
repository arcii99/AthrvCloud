//FormAI DATASET v1.0 Category: QR code reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char qrCode[256];
  
  printf("Enter QR code: ");
  fgets(qrCode, 256, stdin);
  
  if (strlen(qrCode) > 255) {
    printf("Error: QR code too long");
    exit(1);
  }
  
  int numLines = strlen(qrCode) / 8; // each line contains 8 characters
  
  printf("\n\n");
  
  for (int i = 0; i < numLines; i++) {
    char line[9] = "";
    strncpy(line, qrCode + i*8, 8); // copy 8 characters from qrCode starting at index i*8
    
    for (int j = 0; j < 8; j++) {
      if (line[j] == '0') {
        printf("%c", '/');
      } else if (line[j] == '1') {
        printf("%c", '\\');
      } else {
        printf("%c", '*');
      }
    }
    
    printf("\n");
  }
  
  return 0;
}