//FormAI DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char hex[10], clr[10];
  printf("Enter a hex color code (#RRGGBB): ");
  scanf("%s", hex);
  
  // remove hash symbol from input
  int i = 0;
  while(hex[i] != '\0') {
    if(hex[i] == '#') {
      i++;
      continue;
    }
    hex[i-1] = hex[i];
    i++;
  }
  hex[i-1] = '\0';
  
  // convert hex string to integer values
  int r, g, b;
  sscanf(hex, "%02x%02x%02x", &r, &g, &b);

  // convert RGB values to ANSI color code
  int ansir, ansig, ansib;
  ansir = round((double) r / 255 * 5);
  ansig = round((double) g / 255 * 5);
  ansib = round((double) b / 255 * 5);

  // generate ANSI color code string
  snprintf(clr, 10, "\033[38;5;%dm", 16 + ansir * 36 + ansig * 6 + ansib);
  printf("The ANSI color code for %s is %sHello, World!%s\n", hex, clr, "\033[0m");
  return 0;
}