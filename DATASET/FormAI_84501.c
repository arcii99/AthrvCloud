//FormAI DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice, meter, centimeter;

  printf("Welcome to the Unit Converter Program\n\n");
  printf("Please select an option to convert:\n");
  printf("1. Meter to Centimeter\n");
  printf("2. Centimeter to Meter\n");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Enter the length in meters: ");
    scanf("%d", &meter);
    centimeter = meter * 100;
    printf("%d meters = %d centimeters", meter, centimeter);
  } else if (choice == 2) {
    printf("Enter the length in centimeters: ");
    scanf("%d", &centimeter);
    meter = centimeter / 100;
    printf("%d centimeters = %d meters", centimeter, meter);
  } else {
    printf("Invalid option selected");
    exit(0);
  }

  return 0;
}