//FormAI DATASET v1.0 Category: QR code generator ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
  
  printf("Welcome to the C QR Code Generator!\n");
  printf("Please enter the data you would like to encode: \n");

  char data[256]; // Maximum size for QR code data
  scanf("%s",data); // Taking input from user

  // Generating QR code
  char command[256];
  snprintf(command, sizeof(command), "qrencode -o qr.png %s", data);
  system(command);
  
  printf("Your QR code has been generated! \n");

  // Opening the QR code image
  char openCommand[256];
  snprintf(openCommand, sizeof(openCommand), "xdg-open qr.png");
  system(openCommand);

  return 0;
}