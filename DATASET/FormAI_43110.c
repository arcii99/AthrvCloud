//FormAI DATASET v1.0 Category: Temperature monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  double temperature, old_temp = 0.0;
  bool is_first_iteration = true;

  while(true) {
    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    if(temperature < -273.15) {
      printf("Invalid temperature value\n");
      continue;
    }

    if(is_first_iteration) {
      printf("Starting temperature monitor...\n");
      is_first_iteration = false;
    } else {
      if(temperature > old_temp) {
        printf("Temperature is increasing. Old temperature: %.2lf, New temperature: %.2lf\n", old_temp, temperature);
      } else if(temperature == old_temp) {
        printf("Temperature is stable at %.2lf degrees Celsius.\n", temperature);
      } else {
        printf("Temperature is decreasing. Old temperature: %.2lf, New temperature: %.2lf\n", old_temp, temperature);
      }
    }
    old_temp = temperature;
  }

  return 0;
}