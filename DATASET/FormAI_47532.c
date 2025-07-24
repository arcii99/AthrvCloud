//FormAI DATASET v1.0 Category: Color Code Converter ; Style: thoughtful
#include <stdio.h>

int main() {
  int colorCode;
  char colorName[10];
  
  printf("Enter a color code (0-5): ");
  scanf("%d", &colorCode);
  
  switch(colorCode) {
    case 0:
      strcpy(colorName, "Black");
      break;
    case 1:
      strcpy(colorName, "Red");
      break;
    case 2:
      strcpy(colorName, "Green");
      break;
    case 3:
      strcpy(colorName, "Yellow");
      break;
    case 4:
      strcpy(colorName, "Blue");
      break;
    case 5:
      strcpy(colorName, "Magenta");
      break;
    default:
      printf("Invalid color code");
      return 0;
  }
  
  printf("The color is %s.", colorName);
  
  return 0;
}