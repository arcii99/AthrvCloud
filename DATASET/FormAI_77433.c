//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>

int main() {
  char color[10]; // Create a char array to store the color name
  printf("Enter a color name (red, green, blue): ");
  scanf("%s", color); // Store the user input into the color array

  if (strcmp(color, "red") == 0) { // Check if the user input is "red"
    printf("The C color code for red is #FF0000\n");
  } else if (strcmp(color, "green") == 0) { // Check if the user input is "green"
    printf("The C color code for green is #00FF00\n");
  } else if (strcmp(color, "blue") == 0) { // Check if the user input is "blue"
    printf("The C color code for blue is #0000FF\n");
  } else { // If the user input is not one of the three valid colors
    printf("Sorry, that is not a valid color.\n"); // Oops! But we don't say I am Sorry!
  }

  return 0;
}