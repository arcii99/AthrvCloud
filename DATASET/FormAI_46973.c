//FormAI DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char hexCode[7]; // Declare a character array to store the hexadecimal color code entered by the user
  int red, green, blue; // Declare variables to store the red, green, and blue values that we will calculate

  printf("Welcome to the Color Code Converter!\n\n");

  // Prompt the user to enter a hexadecimal color code
  printf("Enter a hexadecimal color code (e.g. #FF0000): ");
  scanf("%s", hexCode); // Read the input from the user and store it in the hexCode array

  // Convert the hexadecimal color code to its corresponding RGB values
  red = (int) strtol(&hexCode[1], NULL, 16); // Convert the first two characters of the hexCode array to an integer
  green = (int) strtol(&hexCode[3], NULL, 16); // Convert the next two characters of the hexCode array to an integer
  blue = (int) strtol(&hexCode[5], NULL, 16); // Convert the last two characters of the hexCode array to an integer

  // Print the RGB values to the console
  printf("\nCongratulations! Your color code (%s) has been converted to the following RGB values:\n", hexCode);
  printf("Red: %d\n", red);
  printf("Green: %d\n", green);
  printf("Blue: %d\n", blue);

  // Generate a random color code and convert it to its RGB values
  printf("\nNow let's generate a random color code and convert it to its RGB values.\n");
  srand(time(NULL)); // Seed the random number generator with the current time
  sprintf(hexCode, "#%02X%02X%02X", rand() % 256, rand() % 256, rand() % 256); // Generate a random hexadecimal color code and store it in the hexCode array
  printf("The randomly generated color code is %s.\n", hexCode);
  red = (int) strtol(&hexCode[1], NULL, 16);
  green = (int) strtol(&hexCode[3], NULL, 16);
  blue = (int) strtol(&hexCode[5], NULL, 16);
  printf("Red: %d\n", red);
  printf("Green: %d\n", green);
  printf("Blue: %d\n", blue);

  printf("\nThank you for using the Color Code Converter. Have a colorful day!\n");

  return 0;
}