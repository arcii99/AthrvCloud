//FormAI DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>

int main() {
  printf("Welcome to the Medieval Color Code Converter!\n");
  
  int colorCode;
  printf("Enter the color code number (0-15): ");
  scanf("%d", &colorCode);
  
  // Check if the entered color code is valid
  if (colorCode < 0 || colorCode > 15) {
    printf("Invalid color code!\n");
    return 1;
  }
  
  // Declare an array of medieval color names
  char* medievalColors[16] = {
    "Crimson", "Scarlet", "Ruby", "Garnet", "Amber", "Topaz", "Sapphire", 
    "Cobalt", "Emerald", "Jade", "Mint", "Olive", "Gold", "Silver", 
    "Bronze", "Iron"
  };
  
  // Print the corresponding medieval color name
  printf("The medieval color for code %d is %s.\n", colorCode, medievalColors[colorCode]);
  
  return 0;
}