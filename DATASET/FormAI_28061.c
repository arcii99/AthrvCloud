//FormAI DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>

int main() {
  float inputNum, outputNum;
  char inputUnit, outputUnit;

  printf("Welcome to the Unit Converter!\n");
  printf("Please enter a number: ");
  scanf("%f", &inputNum);
  printf("Please enter the unit of measurement for your input (F/C, L/Gal, M/FT, etc.): ");
  scanf("%c", &inputUnit); //takes in the newline character left behind by previous input

  //add code to handle inputUnit and convert it to a standardized unit

  printf("What unit of measurement would you like to convert to? ");
  scanf("%c", &outputUnit);

  //add code to handle outputUnit and convert inputNum to desired unit

  printf("%.2f %c is equal to %.2f %c\n", inputNum, inputUnit, outputNum, outputUnit);

  return 0;
}