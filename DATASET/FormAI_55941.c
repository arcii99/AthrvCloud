//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  int tempInput, tempOutput, choice;
  printf("Welcome to the Surreal Temp Converter!\n");
  printf("Please choose from the following options:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("3. I am feeling surreal, let fate decide.\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enter the temperature in Celsius: ");
      scanf("%d", &tempInput);
      tempOutput = (tempInput * 9/5) + 32;
      printf("%d degrees Celsius is %d degrees Fahrenheit.\n", tempInput, tempOutput);
      break;

    case 2:
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%d", &tempInput);
      tempOutput = (tempInput - 32) * 5/9;
      printf("%d degrees Fahrenheit is %d degrees Celsius.\n", tempInput, tempOutput);
      break;

    case 3:
      printf("Let's see what fate has in store for you...\n");
      srand(time(NULL));
      tempInput = rand() % 100;
      printf("Your temperature is %d degrees Celsius.\n", tempInput);
      tempOutput = (tempInput * 9/5) + 32;
      printf("Converting to Fahrenheit... Your surreal temperature is %d degrees Fahrenheit.\n", tempOutput);
      break;

    default:
      printf("Invalid choice. Goodbye.\n");
      break;
  }

  return 0;
}