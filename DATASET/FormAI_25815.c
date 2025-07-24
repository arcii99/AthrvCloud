//FormAI DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>

int main() {
  float celsius, fahrenheit;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  fahrenheit = (celsius * 9/5) + 32;

  printf("%.2f Celsius is equivalent to %.2f Fahrenheit.\n", celsius, fahrenheit);

  printf("\n");

  printf("Would you like to convert another temperature? (Y/N): ");
  char answer;
  scanf(" %c", &answer);

  if (answer == 'Y' || answer == 'y') {
    main();
  } else {
    printf("Thanks for using our converter program!");
  }

  return 0;
}