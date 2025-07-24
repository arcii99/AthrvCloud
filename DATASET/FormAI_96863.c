//FormAI DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>

int main() {
  float input_value;
  char input_unit, output_unit;

  printf("Enter the value and the input unit (C, F, K): ");
  scanf("%f %c", &input_value, &input_unit);

  printf("Enter the output unit (C, F, K): ");
  scanf(" %c", &output_unit);

  float output_value;
  switch (input_unit) {
    case 'C':
      switch (output_unit) {
        case 'C': output_value = input_value; break;
        case 'F': output_value = input_value*9/5 + 32; break;
        case 'K': output_value = input_value + 273.15; break;
        default: printf("Invalid output unit\n"); return 1;
      }
      break;
    case 'F':
      switch (output_unit) {
        case 'C': output_value = (input_value - 32)*5/9; break;
        case 'F': output_value = input_value; break;
        case 'K': output_value = (input_value + 459.67)*5/9; break;
        default: printf("Invalid output unit\n"); return 1;
      }
      break;
    case 'K':
      switch (output_unit) {
        case 'C': output_value = input_value - 273.15; break;
        case 'F': output_value = input_value*9/5 - 459.67; break;
        case 'K': output_value = input_value; break;
        default: printf("Invalid output unit\n"); return 1;
      }
      break;
    default:
      printf("Invalid input unit\n");
      return 1;
  }

  printf("%f %c = %f %c\n", input_value, input_unit, output_value, output_unit);

  return 0;
}