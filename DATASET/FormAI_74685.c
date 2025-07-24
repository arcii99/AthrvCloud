//FormAI DATASET v1.0 Category: QR code reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char qrCode[100];
  printf("Please enter the QR code: ");
  scanf("%s", qrCode);
  
  char* message = malloc(sizeof(char) * 100);
  int sum = 0;

  for(int i = 0; i < strlen(qrCode); i++) {
    sum += (int)qrCode[i];
  }

  sprintf(message, "The sum of the ASCII values in the QR code is %d.", sum);

  printf("%s", message);
  free(message);
  return 0;
}