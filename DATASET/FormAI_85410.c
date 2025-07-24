//FormAI DATASET v1.0 Category: Color Code Converter ; Style: distributed
#include <stdio.h>
#include <string.h>

int main() {
  char input[10];
  char hex[6];
  int r, g, b;

  printf("Enter RGB values separated by commas (ex: 255,255,255): ");
  fgets(input, 10, stdin);

  sscanf(input, "%d,%d,%d", &r, &g, &b);

  sprintf(hex, "%.2X%.2X%.2X", r, g, b);

  printf("Hex Color: #%s\n", hex);

  return 0;
}