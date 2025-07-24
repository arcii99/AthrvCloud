//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {

  char input[7];
  int r, g, b;

  printf("Enter a hexadecimal color code: ");
  scanf("%s", input);

  if (strlen(input) != 6) {
    printf("Invalid color code. Please enter a valid 6-digit hexadecimal color code.\n");
    exit(1);
  }

  r = (int)strtol(input, NULL, 16) >> 16;
  g = (int)strtol(input + 2, NULL, 16) >> 8;
  b = (int)strtol(input + 4, NULL, 16);

  printf("RGB color code: (%d, %d, %d)\n", r, g, b);

  // converting RGB to hexadecimal
  int hexR, hexG, hexB;
  char hexOutput[7];

  printf("\nEnter an RGB color code (separated by commas): ");
  scanf("%d, %d, %d", &hexR, &hexG, &hexB);

  sprintf(hexOutput, "%02X%02X%02X", hexR, hexG, hexB);

  printf("Hexadecimal color code: #%s\n", hexOutput);

  return 0;
}