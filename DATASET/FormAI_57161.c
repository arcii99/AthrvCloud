//FormAI DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>

int main() {

  float temperature = 0;
  int count = 0;
  
  printf("Welcome to Temperature Monitor!\n");
  
  while(count < 10) {
  
    printf("Enter temperature reading in Celsius: ");
    scanf("%f", &temperature);
    
    if(temperature < -273.15) {
      printf("Invalid input! Temperature can't be below absolute zero.\n");
      continue;
    }
    
    // convert temperature to Fahrenheit
    float fahrenheit = (temperature * 9/5) + 32;
    
    // display temperature in Celsius and Fahrenheit
    printf("Temperature in Celsius: %.2f\n", temperature);
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    
    count++;
    
  }
  
  printf("Temperature monitoring stopped.\n");
  
  return 0;
}