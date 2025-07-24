//FormAI DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>

int main() {
   // Welcome message
   printf("Welcome to the Color Code Converter!\n");

   // Prompt the user to select the type of conversion
   printf("What type of conversion would you like to perform?\n");
   printf("1. Convert RGB to HEX\n");
   printf("2. Convert HEX to RGB\n");
   printf("Enter your choice: ");

   // Read user input
   int choice;
   scanf("%d", &choice);

   if (choice == 1) {
      // Convert RGB to HEX
      int r, g, b;
      printf("Enter the RGB values (0-255): ");
      scanf("%d %d %d", &r, &g, &b);

      // Perform the conversion
      int hex = (r << 16) + (g << 8) + b;

      // Print the result
      printf("The HEX code is: #%06X\n", hex);
   } else if (choice == 2) {
      // Convert HEX to RGB
      int hex;
      printf("Enter the HEX code (without the #): ");
      scanf("%X", &hex);

      // Extract the R, G, B values
      int r = (hex >> 16) & 0xFF;
      int g = (hex >> 8) & 0xFF;
      int b = hex & 0xFF;

      // Print the result
      printf("The RGB values are: %d, %d, %d\n", r, g, b);
   } else {
      // Invalid choice
      printf("Invalid choice! Please enter 1 or 2.\n");
   }

   return 0;
}