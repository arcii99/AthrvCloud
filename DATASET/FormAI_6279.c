//FormAI DATASET v1.0 Category: QR code generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main() {
  printf("Welcome to the Happy QR Code Generator! Let's make some magical QR codes!\n");
  
  // Create a string to encode
  char* str_to_encode = "Hello, friend!";
  
  // Create the QR code
  QRcode* qr_code = QRcode_encodeString(str_to_encode, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
  
  // Print the QR code to the console
  for(int i = 0; i < qr_code->width + 2; i++) {
    printf("*");
  }
  printf("\n");
  
  for(int i = 0; i < qr_code->width; i++) {
    printf("*");
    for(int j = 0; j < qr_code->width; j++) {
      if(qr_code->data[i * qr_code->width + j] & 1) {
        printf(" ");
      } else {
        printf("*");
      }
    }
    printf("*\n");
  }
  
  for(int i = 0; i < qr_code->width + 2; i++) {
    printf("*");
  }
  
  printf("\n");
  printf("Hooray! We made a happy QR code!\n");
  QRcode_free(qr_code);
  return 0;
}