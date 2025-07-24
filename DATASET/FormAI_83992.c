//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>

int main() {
  char input[10];
  char output[10];

  printf("Enter input color code (RGB format): ");
  scanf("%s", input);

  if (input[0] == '#') {
    printf("Error: Enter color code without '#' symbol");
    return 0;
  }

  // convert RGB to HEX
  int r, g, b;
  sscanf(input, "%2x%2x%2x", &r, &g, &b);
  sprintf(output, "#%02x%02x%02x", r, g, b);
  printf("HEX code: %s\n", output);
  
  // convert HEX to RGB
  sscanf(input, "#%2x%2x%2x", &r, &g, &b);
  sprintf(output, "%d,%d,%d", r, g, b);
  printf("RGB code: %s", output);

  return 0;
}