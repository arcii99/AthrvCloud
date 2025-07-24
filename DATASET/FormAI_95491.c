//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>

int main() {
  char choice;
  float temp, result;

  printf("Hi there! I am your Temperature Converter.\n");
  printf("Please select the temperature scale you would like to convert:\n");
  printf("Celsius -> Fahrenheit: type 'C'\n");
  printf("Fahrenheit -> Celsius: type 'F'\n");
  scanf("%c", &choice);

  switch(choice) {
    case 'C':
      printf("You chose: Celsius -> Fahrenheit mode. Please enter the temperature in Celsius:\n");
      scanf("%f", &temp);
      result = (temp * 9/5) + 32;
      printf("%.2f Celsius equals to %.2f Fahrenheit.\n", temp, result);
      break;
    case 'F':
      printf("You chose: Fahrenheit -> Celsius mode. Please enter the temperature in Fahrenheit:\n");
      scanf("%f", &temp);
      result = (temp - 32) * 5/9;
      printf("%.2f Fahrenheit equals to %.2f Celsius.\n", temp, result);
      break;
    default:
      printf("Sorry, you chose an invalid option. Please try again!");
  }

  printf("Thank you for using Temperature Converter! I hope you found it helpful.\n");

  return 0;
}