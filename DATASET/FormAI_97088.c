//FormAI DATASET v1.0 Category: QR code generator ; Style: ephemeral
#include <stdio.h>

int main() {
  char qrCode[25][25];
  // QR code matrix size
  int size = 25;
  
  // populate the QR code matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if ((i < 7 && j < 7) || (i < 7 && j > size-8) || (i > size-8 && j < 7) || (i > size-8 && j > size-8)) {
        qrCode[i][j] = '#'; // border
      } else if ((i == 7 && j > 7 && j < size-8) || (i == size-8 && j > 7 && j < size-8) || (j == 7 && i > 7 && i < size-8) || (j == size-8 && i > 7 && i < size-8)) {
        qrCode[i][j] = '+'; // alignment markers
      } else if ((i % 2 == 0 && j % 2 == 0) || (i == 7 && j % 2 == 0) || (j == 7 && i % 2 == 0) || (i == size-8 && j % 2 == 0) || (j == size-8 && i % 2 == 0)) {
        qrCode[i][j] = '.'; // timing markers and format information
      } else {
        qrCode[i][j] = ' '; // empty space
      }
    }
  }
  
  // print the QR code matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%c ", qrCode[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}