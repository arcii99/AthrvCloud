//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

int main() {
  float celsius, fahrenheit, kelvin;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius); 
  
  fahrenheit = (celsius * 9/5) + 32;
  kelvin = celsius + 273.15;
  printf("\n%f Celsius equals to %f Fahrenheit and %f Kelvin.\n", celsius, fahrenheit, kelvin);

  if(fahrenheit > 100){
    printf("\nOh my god! It's boiling outside!\n");
  }
  else if(fahrenheit >= 60 && fahrenheit <= 100){
    printf("\nWow! It's a beautiful day outside.\n");
  }
  else if(fahrenheit >= 32 && fahrenheit < 60){
    printf("\nIt's starting to get chilly.\n");
  }
  else{
    printf("\nI can't feel my fingers, it's too cold!\n");
  }
  
  return 0;
}