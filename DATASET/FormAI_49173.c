//FormAI DATASET v1.0 Category: Unit converter ; Style: surrealist
#include <stdio.h>

int main() {

  float input;
  char unit;

  printf("Welcome to the Surrealist Unit Converter!\n");
  printf("Please enter a value and its unit (m, kg, s): ");
  scanf("%f %c", &input, &unit);

  if (unit == 'm') {
    printf("%f meters is equal to %f dreams.\n", input, input*3.1415);
  }
  else if (unit == 'kg') {
    printf("%f kilograms is equal to %f surrealists.\n", input, input/2);
  }
  else if (unit == 's') {
    printf("%f seconds is equal to %f nightmares.\n", input, input+13);
  }
  else {
    printf("Sorry, that unit is not supported by this converter. \n");
  }

  return 0;
}