//FormAI DATASET v1.0 Category: Color Code Converter ; Style: paranoid
// Paranoid Color Code Converter Program
#include <stdio.h>

int main() {
  // Declare variables
  char hex[7]; 
  int red, green, blue;
  
  // Get hex code input from user
  printf("Enter a 6-digit hex code: ");
  scanf("%s", hex);
  
  // Verify input is 6 digits
  if (strlen(hex) != 6) {
    printf("Invalid hex code\n");
    return 1;
  }
  
  // Verify input contains only valid characters
  for (int i=0; i<6; i++) {
    if (!isdigit(hex[i]) && (hex[i] < 'A' || hex[i] > 'F') && (hex[i] < 'a' || hex[i] > 'f')) {
      printf("Invalid hex code\n");
      return 1;
    }
  }
  
  // Convert hex code to RGB values
  sscanf(hex, "%02X%02X%02X", &red, &green, &blue);
  
  // Verify RGB values are valid
  if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
    printf("Invalid RGB values\n");
    return 1;
  }
  
  // Convert RGB values to C color code
  printf("The C color code is: ");
  
  if (red == 0 && green == 0 && blue == 0) {
    printf("0x00");
  } else if (red == 255 && green == 255 && blue == 255) {
    printf("0xffffff");
  } else {
    printf("0x%02x%02x%02x", red, green, blue);
  }
  
  return 0;
}