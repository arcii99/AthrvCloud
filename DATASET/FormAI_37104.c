//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>

int main(){
  printf("Enter your color code in HEX (#): ");
  char hex[7];
  scanf("%s", hex);

  // Check if input is valid
  if(hex[0] != '#' || strlen(hex) != 7){
    printf("Invalid input format!");
    return 1;
  }

  // Convert HEX to RGB
  int r = (int)strtol(&hex[1], NULL, 16) >> 16;
  int g = (int)strtol(&hex[3], NULL, 16) >> 8;
  int b = (int)strtol(&hex[5], NULL, 16);

  // Print RGB values
  printf("RGB values: %d %d %d\n", r, g, b);

  // Check for grayscale
  if(r == g && g == b){
    printf("Color is grayscale.\n");
  }

  // Check for primary colors
  if(r > g && r > b){
    printf("Color is mostly red.\n");
  } else if(g > r && g > b){
    printf("Color is mostly green.\n");
  } else if(b > r && b > g){
    printf("Color is mostly blue.\n");
  }

  // Check for complementary color
  int comp_r = 255 - r;
  int comp_g = 255 - g;
  int comp_b = 255 - b;
  printf("Complementary color: #%02X%02X%02X\n", comp_r, comp_g, comp_b);

  return 0;
}