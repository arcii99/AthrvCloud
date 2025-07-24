//FormAI DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>

int main() {
  char from_unit[10], to_unit[10];
  float value, result;

  printf("Welcome to the Unique Unit Converter!\n\n");

  // Prompt user to enter value and units
  printf("Enter the value to be converted: ");
  scanf("%f", &value);

  printf("\nEnter the unit to be converted from: ");
  scanf("%s", from_unit);

  printf("\nEnter the unit to be converted to: ");
  scanf("%s", to_unit);

  // Start conversion
  if (strcmp(from_unit, "inch") == 0) {
    if (strcmp(to_unit, "feet") == 0) {
      result = value / 12;
    } else if (strcmp(to_unit, "centimeter") == 0) {
      result = value * 2.54;
    } else {
      printf("Invalid unit to convert to.\n");
      return 0;
    }
  } else if (strcmp(from_unit, "pound") == 0) {
    if (strcmp(to_unit, "kilogram") == 0) {
      result = value * 0.45359237;
    } else if (strcmp(to_unit, "ounce") == 0) {
      result = value * 16;
    } else {
      printf("Invalid unit to convert to.\n");
      return 0;
    }
  } else {
    printf("Invalid unit to convert from.\n");
    return 0;
  }

  // Display result
  printf("\n%0.2f %s = %0.2f %s", value, from_unit, result, to_unit);

  return 0;
}