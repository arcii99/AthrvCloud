//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>

int main() {
  char hex[10];
  int r, g, b;

  printf("Enter a valid HEX color code (including the # symbol): ");
  scanf("%s", hex);

  r = (hex[1] < 'A' ? hex[1] - '0' : hex[1] - 'A' + 10) * 16 + (hex[2] < 'A' ? hex[2] - '0' : hex[2] - 'A' + 10);
  g = (hex[3] < 'A' ? hex[3] - '0' : hex[3] - 'A' + 10) * 16 + (hex[4] < 'A' ? hex[4] - '0' : hex[4] - 'A' + 10);
  b = (hex[5] < 'A' ? hex[5] - '0' : hex[5] - 'A' + 10) * 16 + (hex[6] < 'A' ? hex[6] - '0' : hex[6] - 'A' + 10);

  printf("RGB Color code for %s is %d, %d, %d\n", hex, r, g, b);

  return 0;
}