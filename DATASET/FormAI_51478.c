//FormAI DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main ()
{
  // Input RGB values
  int red, green, blue;

  printf("Enter the red value (0-255): ");
  scanf("%d", &red);
  printf("Enter the green value (0-255): ");
  scanf("%d", &green);
  printf("Enter the blue value (0-255): ");
  scanf("%d", &blue);

  // Convert RGB values to C Color Code
  int code = ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff);

  // Print the C Color Code Value
  printf("The C Color Code is: %06x\n", code);

  return 0;
}