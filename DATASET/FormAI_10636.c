//FormAI DATASET v1.0 Category: Color Code Converter ; Style: excited
#include <stdio.h>

int main() {
  
  printf("\nWelcome to the fantastic Color Code Converter!!!\n");
  printf("We will convert your color hex code to RGB Color, or RGB Color to Hex Code!\n");
  printf("Just choose what you need!\n\n");

  char option;
  printf("Enter (1) if you want to convert Hex to RGB Color\nEnter (2) if you want to convert RGB Color to Hex\n\n");
  scanf("%c", &option);

  if (option == '1') {
    char hex[7];
    printf("Enter hex color code (must be 6 characters long): ");
    scanf("%s", hex);
    
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    printf("RGB Color: %d, %d, %d\n", r, g, b);

  } else if (option == '2') {
    int r, g, b;
    printf("Enter RGB Color code (r,g,b - must be separated by commas): ");
    scanf("%d,%d,%d", &r, &g, &b);

    char hex[7];
    sprintf(hex, "%02x%02x%02x", r, g, b);
    printf("Hex Color Code: #%s\n", hex);

  } else {
    printf("Invalid option, bye!\n");
  }

  printf("\nThanks for using Color Code Converter! Have a nice day!\n");

  return 0;
}