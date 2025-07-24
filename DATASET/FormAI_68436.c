//FormAI DATASET v1.0 Category: Temperature monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float temp_c, temp_f;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &temp_c);
  temp_f = (temp_c * 9/5) + 32;
  printf("Temperature in Fahrenheit: %.2f F\n", temp_f);

  if(temp_c < 0)
  {
    printf("It's freezing outside. Bundle up!\n");
  }
  else if(temp_c >= 0 && temp_c < 20)
  {
    printf("It's a bit chilly today. Wear a jacket!\n");
  }
  else if(temp_c >= 20 && temp_c < 30)
  {
    printf("It's a lovely day outside. Enjoy it!\n");
  }
  else
  {
    printf("It's quite hot today. Stay hydrated!\n");
  }

  return 0;
}