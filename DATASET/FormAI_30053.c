//FormAI DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

int main() {
  double inputVal, outputVal;
  char inputUnit[10], outputUnit[10];
  
  printf("Welcome to the Unit Converter!\n");
  printf("Please enter the value to convert: ");
  scanf("%lf", &inputVal);
  
  printf("Please enter the unit of measure for the input (e.g. meters): ");
  scanf("%s", inputUnit);
  
  printf("Please enter the unit of measure for the output (e.g. feet): ");
  scanf("%s", outputUnit);
  
  if(strcmp(inputUnit, "meters") == 0 && strcmp(outputUnit, "feet") == 0) {
    outputVal = inputVal * 3.28084;
  } else if(strcmp(inputUnit, "feet") == 0 && strcmp(outputUnit, "meters") == 0) {
    outputVal = inputVal / 3.28084;
  } else if(strcmp(inputUnit, "celcius") == 0 && strcmp(outputUnit, "fahrenheit") == 0) {
    outputVal = (inputVal * (9.0 / 5.0)) + 32.0;
  } else if(strcmp(inputUnit, "fahrenheit") == 0 && strcmp(outputUnit, "celcius") == 0) {
    outputVal = (inputVal - 32.0) * (5.0 / 9.0);
  } else if(strcmp(inputUnit, "kilograms") == 0 && strcmp(outputUnit, "pounds") == 0) {
    outputVal = inputVal * 2.20462;
  } else if(strcmp(inputUnit, "pounds") == 0 && strcmp(outputUnit, "kilograms") == 0) {
    outputVal = inputVal / 2.20462;
  } else {
    printf("Invalid units received, cannot perform conversion.");
    return -1;
  }
  
  printf("%lf %s equals %lf %s\n", inputVal, inputUnit, outputVal, outputUnit);
  
  return 0;
}