//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>

int main() {
  
  char celsius_deg[100];
  double celsius, kelvin, fahrenheit;
  
  printf("Enter temperature in Celsius: ");
  fgets(celsius_deg, sizeof(celsius_deg), stdin);
  
  celsius = strtod(celsius_deg, NULL);

  kelvin = celsius + 273.15;
  fahrenheit = (celsius * (9.0 / 5.0)) + 32;
  
  printf("\nHmm..., let me convert that for you...\n");
  sleep(1);  // A bit of suspense before revealing the results
  
  printf("\nIn Kelvin: %.2f K\n", kelvin);
  printf("In Fahrenheit: %.2f F\n", fahrenheit);
  
  printf("\nVoila! My mission here is complete.\n\n");
  
  return 0;
}