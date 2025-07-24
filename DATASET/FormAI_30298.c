//FormAI DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>

int main() {
  double setTemp, currTemp, temp;
  int status = 0;

  printf("Enter the temperature to monitor (in celsius): ");
  scanf("%lf", &setTemp);

  while (1) {
    // Read current temperature
    printf("Enter the current temperature (in celsius): ");
    scanf("%lf", &currTemp);

    // Check if current temperature is equal to set temperature
    if (currTemp == setTemp) {
      printf("Temperature has reached the set value of %.2lf C.", setTemp);
      break;
    }

    // Check if temperature is above set temperature
    if (currTemp > setTemp) {
      temp = currTemp - setTemp;
      printf("Temperature is above the set value by %.2lf C.\n", temp);
      if (status != 1) {
        printf("ALERT! Temperature is above the set value!\n");
        status = 1;
      }
    }

    // Check if temperature is below set temperature
    if (currTemp < setTemp) {
      temp = setTemp - currTemp;
      printf("Temperature is below the set value by %.2lf C.\n", temp);
      if (status != -1) {
        printf("ALERT! Temperature is below the set value!\n");
        status = -1;
      }
    }
  }

  return 0;
}