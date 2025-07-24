//FormAI DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  int choice;
  float value;
  printf("Welcome to the post-apocalyptic unit converter!\n\n");
  do {
    printf("Choose the unit you want to convert:\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Gallons to Liters\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("\nEnter the value in miles: ");
        scanf("%f", &value);
        printf("%.2f miles is equal to %.2f kilometers.\n\n", value, value * 1.60934);
        break;
      case 2:
        printf("\nEnter the value in Fahrenheit: ");
        scanf("%f", &value);
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n\n", value, (value - 32) * 5/9);
        break;
      case 3:
        printf("\nEnter the value in gallons: ");
        scanf("%f", &value);
        printf("%.2f gallons is equal to %.2f liters.\n\n", value, value * 3.78541);
        break;
      case 4:
        printf("\nThank you for using the post-apocalyptic unit converter!\n");
        break;
      default:
        printf("\nInvalid choice! Please choose a valid option.\n\n");
        break;
    }
  } while(choice != 4);
  return 0;
}