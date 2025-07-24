//FormAI DATASET v1.0 Category: QR code reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define QR Code structure
typedef struct {
  int version;
  char data[1000];
} QRCode;

// Function to read QR Code
bool readQRCode(char *filename, QRCode *qr) {
  
  // open file for reading in binary mode
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    return false;
  }
  
  // read version if available
  fread(&qr->version, sizeof(int), 1, file);
  
  // read data
  fread(qr->data, sizeof(char), sizeof(qr->data), file);
  
  // close file and return true
  fclose(file);
  return true;
}

int main(int argc, char **argv) {
  
  // create QRCode struct
  QRCode qr;

  // read QR code from file
  bool success = readQRCode("qrcode.bin", &qr);
  if (!success) {
    printf("Failed to read QR code file.\n");
    return 1;
  }
  
  // print QR code version and data
  printf("QR Code Version: %d\n", qr.version);
  printf("QR Code Data: %s\n", qr.data);
  
  return 0;
}