//FormAI DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
  float temperature;
  int high_temp_count = 0;
  int low_temp_count = 0;

  printf("Welcome to the temperature monitor program!\n");

  while (1) {
    printf("Enter the current temperature in Celsius: ");
    scanf("%f", &temperature);

    if (temperature > 28.0) {
      printf("Temperature is high.\n");
      high_temp_count++;
    } else if (temperature < 10.0) {
      printf("Temperature is low.\n");
      low_temp_count++;
    } else {
      printf("Temperature is normal.\n");
    }

    printf("\n");

    printf("Number of times the temperature was high: %d\n", high_temp_count);
    printf("Number of times the temperature was low: %d\n", low_temp_count);

    printf("\n");

    printf("Do you want to continue? (Y/N) ");

    char answer;
    scanf(" %c", &answer);

    if (answer != 'Y' && answer != 'y') {
      break;
    }
  }

  printf("Thank you for using the temperature monitor program!\n");

  return 0;
}