//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

int main() {

  printf("Welcome to the Happy Unit Converter!\n");
  printf("We're here to make your day a little brighter by doing some unit conversions.\n\n");

  // length conversion
  float inches, centimeters;
  printf("First, let's convert inches to centimeters.\n");
  printf("How many inches do you have? ");
  scanf("%f", &inches);
  centimeters = inches * 2.54;
  printf("Woohoo! You now have %.2f centimeters.\n\n", centimeters);

  // weight conversion
  float pounds, kilograms;
  printf("Next up, let's convert pounds to kilograms.\n");
  printf("How many pounds do you weigh? ");
  scanf("%f", &pounds);
  kilograms = pounds / 2.205;
  printf("Amazing! You now weigh %.2f kilograms.\n\n", kilograms);

  // temperature conversion
  float fahrenheit, celsius;
  printf("Lastly, let's convert Fahrenheit to Celsius.\n");
  printf("What's the temperature in Fahrenheit? ");
  scanf("%f", &fahrenheit);
  celsius = (fahrenheit - 32) * 5/9;
  printf("Hooray! It's %.2f degrees Celsius now.\n\n", celsius);

  printf("Thanks for using the Happy Unit Converter! Have a great day!\n");

  return 0;
}