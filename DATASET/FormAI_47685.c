//FormAI DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>

int main() {

  int option;
  float value;
  printf("Welcome to Unit Converter!\n");
  printf("Choose an option:\n 1. Feet to meters\n 2. Pounds to kilograms\n 3. Miles to kilometers\n");
  scanf("%d", &option);

  switch(option) {

    case 1:
      printf("Enter value in feet:");
      scanf("%f", &value);
      printf("%.2f feet is equal to %.2f meters.\n", value, value*0.3048);
      break;

    case 2:
      printf("Enter value in pounds:");
      scanf("%f", &value);
      printf("%.2f pounds is equal to %.2f kilograms.\n", value, value*0.453592);
      break;

    case 3:
      printf("Enter value in miles:");
      scanf("%f", &value);
      printf("%.2f miles is equal to %.2f kilometers.\n", value, value*1.60934);
      break;

    default:
      printf("Invalid option! Please select again.\n");
      break;

  }

  return 0;
}