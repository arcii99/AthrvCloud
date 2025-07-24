//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int hexToDec(char hexChar) {
  if ('0' <= hexChar && hexChar <= '9') {
    return hexChar - '0';
  } else if ('a' <= hexChar && hexChar <= 'f') {
    return hexChar - 'a' + 10;
  } else if ('A' <= hexChar && hexChar <= 'F') {
    return hexChar - 'A' + 10;
  } else {
    printf("Invalid hex character: %c", hexChar);
    exit(1);
  }
}

int hexToRgb(char *hex, int *red, int *green, int *blue) {
  if (hex[0] == '#') {
    hex++;
  }

  if (strlen(hex) == 3) {
    *red = hexToDec(hex[0]) * 16 + hexToDec(hex[0]);
    *green = hexToDec(hex[1]) * 16 + hexToDec(hex[1]);
    *blue = hexToDec(hex[2]) * 16 + hexToDec(hex[2]);
    return 1;
  } else if (strlen(hex) == 6) {
    *red = hexToDec(hex[0]) * 16 + hexToDec(hex[1]);
    *green = hexToDec(hex[2]) * 16 + hexToDec(hex[3]);
    *blue = hexToDec(hex[4]) * 16 + hexToDec(hex[5]);
    return 1;
  } else {
    printf("Invalid hex code: %s", hex);
    exit(1);
  }
}

int main() {
  char hex[7];
  int red, green, blue;
  printf("Enter hex code (with/without '#' prefix): ");
  scanf("%s", hex);

  if (hexToRgb(hex, &red, &green, &blue)) {
    printf("RGB values: %d, %d, %d", red, green, blue);
  }

  return 0;
}