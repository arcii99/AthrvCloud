//FormAI DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>

int main ()
{
  float celsius, fahrenheit;
  
  printf("Greetings, traveller!\n");
  printf("What is the temperature in Celsius degrees?\n");
  scanf("%f", &celsius);
  
  fahrenheit = (celsius * 9/5) + 32; //conversion formula
  
  printf("Ah, I understand! That would be %f degrees Fahrenheit.\n", fahrenheit);
  printf("Stay warm on your journey!\n");
  
  return 0;
}