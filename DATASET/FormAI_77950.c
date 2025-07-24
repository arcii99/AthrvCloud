//FormAI DATASET v1.0 Category: Temperature monitor ; Style: protected
#include <stdio.h>

int main() {
  float temperature = 0;
  int alarm = 0;
  printf("Enter current temperature in Celsius: ");
  scanf("%f", &temperature);

  if(temperature > 100) {
    printf("Temperature is above boiling point!\n");
    alarm = 1;
  }
  else if (temperature < 0) {
    printf("Temperature is below freezing point!\n");
    alarm = 1;
  }
  else {
    printf("Temperature is within normal range.\n");
  }

  if(alarm) {
    printf("Temperature sensor has detected a problem. Please contact maintenance!\n");
  }
  else {
    printf("Temperature sensor is functioning normally.\n");
  }

  return 0;
}