//FormAI DATASET v1.0 Category: Temperature Converter ; Style: introspective
#include<stdio.h>

int main(){
  float celsius,fahrenheit;

  printf("Enter temperature in Celsius: ");
  scanf("%f",&celsius);

  // Celsius to Fahrenheit conversion formula
  fahrenheit = (celsius * 9/5) + 32;

  printf("%.2f Celsius = %.2f Fahrenheit",celsius,fahrenheit);

  return 0;
}