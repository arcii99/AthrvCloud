//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>

int main(void) {
  int temperature = 0;
  printf("Greetings traveler, please tell me the temperature outside in Celsius.\n");
  scanf("%d", &temperature);

  if (temperature < 0) {
    printf("The temperature is too cold, thy bones shall shiver!\n");
  } else if (temperature >= 0 && temperature < 10) {
    printf("The temperature is cold but bearable.\n");
  } else if (temperature >= 10 && temperature < 20) {
    printf("The temperature is mild and pleasant.\n");
  } else if (temperature >= 20 && temperature < 30) {
    printf("The temperature is warm and cozy.\n");
  } else if (temperature >= 30 && temperature < 40) {
    printf("The temperature is too hot for my taste, I prefer it cooler.\n");
  } else {
    printf("I cannot bear this scorching heat! Please, make it cooler.\n");
  }

  return 0;
}