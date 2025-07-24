//FormAI DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>

int main() {
  float temperature;
  printf("Please enter current temperature in Celsius: ");
  scanf("%f", &temperature);
  float fahrenheit = temperature * 9/5 + 32;
  printf("Current temperature in Fahrenheit is: %.2f\n", fahrenheit);

  if (fahrenheit > 90) {
    printf("It's really hot outside. Stay hydrated!\n");
  } else if (fahrenheit > 70) {
    printf("It's a pleasant day. Enjoy the weather!\n");
  } else if (fahrenheit > 50) {
    printf("It's a bit cool outside. Bring a jacket.\n");
  } else {
    printf("It's freezing outside. Bundle up!\n");
  }
  
  return 0;
}