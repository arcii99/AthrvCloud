//FormAI DATASET v1.0 Category: Unit converter ; Style: Alan Touring
#include <stdio.h>

int main() {
  int choice;
  float value;

  printf("Welcome to the Length Unit Converter!\n");
  printf("Choose an option:\n");
  printf("1. Inches to Centimeters\n");
  printf("2. Feet to Meters\n");
  printf("3. Yards to Meters\n");
  printf("4. Miles to Kilometers\n");

  scanf("%d", &choice);

  printf("Enter the value you want to convert:\n");
  scanf("%f", &value);

  switch(choice) {
    case 1:
      printf("%.2f inches converts to %.2f centimeters.\n", value, value * 2.54);
      break;
    case 2:
      printf("%.2f feet converts to %.2f meters.\n", value, value * 0.3048);
      break;
    case 3:
      printf("%.2f yards converts to %.2f meters.\n", value, value * 0.9144);
      break;
    case 4:
      printf("%.2f miles converts to %.2f kilometers.\n", value, value * 1.60934);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}