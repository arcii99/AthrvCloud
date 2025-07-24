//FormAI DATASET v1.0 Category: Unit converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {

  float input_value = 0;
  float converted_value = 0;
  char input_unit[50];
  char converted_unit[50];

  printf("Welcome to the Surreal Unit Converter\n\n");

  printf("Enter a value to convert: ");
  scanf("%f", &input_value);

  printf("Enter the unit of the value you entered: ");
  scanf("%s", input_unit);

  printf("Enter the unit to convert to: ");
  scanf("%s", converted_unit);

  printf("\nConverting %f %s to %s...\n", input_value, input_unit, converted_unit);

  if (strcmp(input_unit, "dreams") == 0 && strcmp(converted_unit, "reality") == 0) {
    converted_value = input_value / 2;
  }
  else if (strcmp(input_unit, "illusions") == 0 && strcmp(converted_unit, "truths") == 0) {
    converted_value = input_value * 3;
  }
  else if (strcmp(input_unit, "fantasies") == 0 && strcmp(converted_unit, "actualities") == 0) {
    converted_value = input_value * 5;
  }
  else if (strcmp(input_unit, "nightmares") == 0 && strcmp(converted_unit, "happiness") == 0) {
    converted_value = input_value * -1;
  }
  else {
    printf("\nConversion not supported. Please try again.\n");
    exit(1);
  }

  printf("\n%f %s = %f %s\n", input_value, input_unit, converted_value, converted_unit);

  return 0;
}