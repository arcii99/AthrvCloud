//FormAI DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>

int main() {
  float length, width; // initialize variables
  printf("Enter length in meters: ");
  scanf("%f", &length);
  printf("Enter width in meters: ");
  scanf("%f", &width);

  // Conversion factors
  float meterToFeet = 3.28084;
  float meterToInches = 39.3701;

  // Conversion calculations
  float feet = length * meterToFeet;
  float inches = width * meterToInches;

  printf("Converted values:\n");
  printf("Length in feet: %.2f ft\n", feet);
  printf("Width in inches: %.2f in\n", inches);

  return 0;
}