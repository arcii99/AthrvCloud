//FormAI DATASET v1.0 Category: QR code reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_LEN 100

void readQRCode(char qrCode[MAX_QR_CODE_LEN])
{
  printf("Please scan your QR code: \n");
  fgets(qrCode, MAX_QR_CODE_LEN, stdin);
  qrCode[strcspn(qrCode, "\r\n")] = 0;
}

bool isValidQRCode(char qrCode[MAX_QR_CODE_LEN])
{
  int len = strlen(qrCode);
  if (len < 6 || qrCode[0] != 'C' || qrCode[1] != '-' || qrCode[len - 1] != '-')
    return false;
  
  for (int i = 2; i < len - 1; i++)
  {
    if (qrCode[i] < '0' || qrCode[i] > '9')
      return false;
  }
  
  return true;
}

void processQRCode(char qrCode[MAX_QR_CODE_LEN])
{
  // do something with the valid QR code
  printf("QR code %s is valid!\n", qrCode);
}

int main()
{
  char qrCode[MAX_QR_CODE_LEN];
  readQRCode(qrCode);
  if (isValidQRCode(qrCode))
    processQRCode(qrCode);
  else
    printf("Invalid QR code!\n");
  
  return 0;
}