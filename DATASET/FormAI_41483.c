//FormAI DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>

int main() {
  int temper_f, temper_c, lower, upper, increment;

  printf("Enter lower limit in Fahrenheit: ");
  scanf("%d", &lower);

  printf("Enter upper limit in Fahrenheit: ");
  scanf("%d", &upper);

  printf("Enter temperature increment: ");
  scanf("%d", &increment);

  printf("\nFahrenheit\tCelsius\n");
  printf("------------------------\n");

  for (temper_f = lower; temper_f <= upper; temper_f += increment) {
    temper_c = (temper_f - 32) * 5/9;
    printf("%d\t\t%d\n", temper_f, temper_c);
  }

  return 0;
}