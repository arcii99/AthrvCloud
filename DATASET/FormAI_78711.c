//FormAI DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char unit[3];
  float temp, convertedTemp = 0;
  
  printf("Enter temperature: ");
  scanf("%f", &temp);
  printf("Enter unit of temperature (F/C): ");
  scanf("%s", unit);

  if(strcmp(unit, "F") == 0) {
    convertedTemp = (temp - 32) * 5 / 9;
    printf("%.2f F = %.2f C\n", temp, convertedTemp);
  } else if (strcmp(unit, "C") == 0) {
    convertedTemp = (temp * 9 / 5) + 32;
    printf("%.2f C = %.2f F\n", temp, convertedTemp);
  } else {
    printf("Invalid unit entered. Please enter 'F' or 'C'\n");
  }
  
  return 0;
}