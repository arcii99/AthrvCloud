//FormAI DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>

// Converting hex to RGB
void hex_to_rgb(char hex[], int* r, int* g, int* b) {
  sscanf(hex, "#%02x%02x%02x", r, g, b);
}

// Converting RGB to hex
void rgb_to_hex(int r, int g, int b, char hex[]) {
  sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Main function
int main() {
  char hex[8];
  int r, g, b;
  
  // Input from user
  printf("Enter the hex color code: ");
  scanf("%s", hex);
  
  // Converting hex to RGB
  hex_to_rgb(hex, &r, &g, &b);
  
  // Printing the RGB values
  printf("RGB value is: (%d, %d, %d)\n", r, g, b);
  
  // Converting RGB to hex
  char new_hex[8];
  rgb_to_hex(r, g, b, new_hex);
  
  // Printing the hex code
  printf("Hex color code is: %s\n", new_hex);
  
  return 0;
}