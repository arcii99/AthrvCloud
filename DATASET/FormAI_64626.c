//FormAI DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>

int main() {
  int input_unit, output_unit;
  float input_value, output_value;

  printf("Welcome to the Scientific Unit Converter!\n");

  // Get input unit
  printf("Enter your input unit:\n");
  printf("1. Meter\n");
  printf("2. Kilometer\n");
  printf("3. Millimeter\n");
  scanf("%d", &input_unit);

  // Get output unit
  printf("Enter your output unit:\n");
  printf("1. Meter\n");
  printf("2. Kilometer\n");
  printf("3. Millimeter\n");
  scanf("%d", &output_unit);

  // Get input value
  printf("Enter your input value:\n");
  scanf("%f", &input_value);

  // Convert units
  if (input_unit == 1 && output_unit == 2) { // Meter to Kilometer
    output_value = input_value / 1000.0;
  } else if (input_unit == 1 && output_unit == 3) { // Meter to Millimeter
    output_value = input_value * 1000.0;
  } else if (input_unit == 2 && output_unit == 1) { // Kilometer to Meter
    output_value = input_value * 1000.0;
  } else if (input_unit == 2 && output_unit == 3) { // Kilometer to Millimeter
    output_value = input_value * 1000000.0;
  } else if (input_unit == 3 && output_unit == 1) { // Millimeter to Meter
    output_value = input_value / 1000.0;
  } else if (input_unit == 3 && output_unit == 2) { // Millimeter to Kilometer
    output_value = input_value / 1000000.0;
  } else { // Invalid input/output unit
    printf("Invalid input/output unit selected.\n");
    return 1;
  }

  // Print output value
  printf("Output value: %f\n", output_value);

  return 0;
}