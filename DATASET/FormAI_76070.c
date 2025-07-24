//FormAI DATASET v1.0 Category: Color Code Converter ; Style: grateful
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the C Color Code Converter!\n\n");
  
  // Prompt for input color code
  printf("Please enter the color code you want to convert: ");
  
  // Input for color code
  char color_code[7];
  scanf("%s", color_code);
  
  // Separate input into RGB values
  char r[3] = {color_code[0], color_code[1], '\0'};
  char g[3] = {color_code[2], color_code[3], '\0'};
  char b[3] = {color_code[4], color_code[5], '\0'};
  
  // Convert hex values to decimal values
  int red = strtol(r, NULL, 16);
  int green = strtol(g, NULL, 16);
  int blue = strtol(b, NULL, 16);
  
  // Print decimal values
  printf("\nThe decimal values of the color code %s are:\n", color_code);
  printf("Red: %d\nGreen: %d\nBlue: %d\n", red, green, blue);
  
  // Pause
  printf("\nPress enter to continue...");
  getchar();
  
  // Convert decimal values to hex values
  sprintf(r, "%02X", red);
  sprintf(g, "%02X", green);
  sprintf(b, "%02X", blue);
  
  // Merge hex values into color code
  char new_color_code[7];
  snprintf(new_color_code, 7, "%s%s%s", r, g, b);
  
  // Print new color code
  printf("\nThe new color code is: %s", new_color_code);
  
  return 0;
}