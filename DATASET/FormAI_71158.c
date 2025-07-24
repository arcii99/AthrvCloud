//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>

int main() {
  float temp_cel, temp_fah;

  printf("Enter the temperature in Celsius: ");
  scanf("%f", &temp_cel);

  // Celsius to Fahrenheit conversion formula
  temp_fah = (temp_cel * 9 / 5) + 32;

  printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temp_cel, temp_fah);

  return 0;
}