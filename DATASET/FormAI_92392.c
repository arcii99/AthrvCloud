//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // calculating Fahrenheit
  fahrenheit = (celsius * 9 / 5) + 32;

  printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
  printf("\n\nI can't believe Celsius and Fahrenheit are so different!");
  printf("\nWhy do we have to convert temperature units anyway?!");
  printf("\nIt just makes everything so confusing!\n");
  
  return 0;
}