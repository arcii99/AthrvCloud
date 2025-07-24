//FormAI DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main() {
  float temperature;
  char temp_type;
  
  printf("Enter the temperature value: ");
  scanf("%f", &temperature);
  
  // Checking whether the temperature value is correct or not.
  if(temperature < -273.15) {
    printf("Invalid temperature value, No temperature can be this low! \n");
    exit(0);
  }

  printf("Enter the temperature type, (C) for Celsius or (F) for Fahrenheit: ");
  scanf(" %c", &temp_type);

  if(temp_type == 'C' || temp_type == 'c') {
    float fahrenheit = (temperature * 9/5) + 32;
    printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit.\n", temperature, fahrenheit);
  } else if(temp_type == 'F' || temp_type == 'f') {
      float celsius = (temperature - 32) * 5/9;
      printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius.\n", temperature, celsius);
  } else {
      printf("Invalid temperature type! Please enter either (C) for Celsius or (F) for Fahrenheit.\n");
  }
  return 0;
}