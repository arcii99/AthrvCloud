//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  char c;
  int r, g, b;
  printf("Enter the color code in Hex format (e.g. #FF5733): #");
  scanf("%c", &c);
  printf("\n");

  if (c >= 'A' && c <= 'F') {
    r = c - 'A' + 10;
  } else if (c >= 'a' && c <= 'f') {
    r = c - 'a' + 10;
  } else {
    r = c - '0';
  }

  scanf("%c", &c);

  if (c >= 'A' && c <= 'F') {
    g = c - 'A' + 10;
  } else if (c >= 'a' && c <= 'f') {
    g = c - 'a' + 10;
  } else {
    g = c - '0';
  }

  scanf("%c", &c);

  if (c >= 'A' && c <= 'F') {
    b = c - 'A' + 10;
  } else if (c >= 'a' && c <= 'f') {
    b = c - 'a' + 10;
  } else {
    b = c - '0';
  }

  printf("\nThe RGB values of the color code #%.2x%.2x%.2x are:\n", r, g, b);
  printf("Red: %d\nGreen: %d\nBlue: %d\n", r * 17, g * 17, b * 17);

  return 0;
}