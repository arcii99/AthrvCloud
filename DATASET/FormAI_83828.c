//FormAI DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>
#include <string.h>

int convertHexToDecimal(char hex[]) {
   int len = strlen(hex);
   int base = 1;
   int decimal = 0;
   int i;
   for (i = len - 1; i >= 0; i--) {
      if (hex[i] >= '0' && hex[i] <= '9') {
         decimal += (hex[i] - 48) * base;
         base = base * 16;
      } else if (hex[i] >= 'A' && hex[i] <= 'F') {
         decimal += (hex[i] - 55) * base;
         base = base * 16;
      } else if (hex[i] >= 'a' && hex[i] <= 'f') {
         decimal += (hex[i] - 87) * base;
         base = base * 16;
      }
   }
   return decimal;
}

void convertDecimalToRgb(int decimal, int *r, int *g, int *b) {
   *r = (decimal & 0xFF0000) >> 16;
   *g = (decimal & 0x00FF00) >> 8;
   *b = (decimal & 0x0000FF);
}

void convertHexToRgb(char hex[], int *r, int *g, int *b) {
   int decimal = convertHexToDecimal(hex);
   convertDecimalToRgb(decimal, r, g, b);
}

int main() {
   char hex[] = "9B2323";
   int r, g, b;
   convertHexToRgb(hex, &r, &g, &b);
   printf("Hex: #%s\nRGB: %d,%d,%d", hex, r, g, b);
   return 0;
}