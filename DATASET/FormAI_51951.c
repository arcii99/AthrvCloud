//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);
  
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  
  printf("\n%.1f degrees Celsius is equal to %.1f degrees Fahrenheit.", celsius, fahrenheit);
  
  return 0;
}