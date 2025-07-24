//FormAI DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>

int main() {
  int choice;
  float value;

  printf("Welcome to Medieval Converter!\n");
  printf("Please select the unit you wish to convert:\n");
  printf("1) Pounds to Kilograms\n");
  printf("2) Feet to Meters\n");

  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enter the number of pounds: ");
      scanf("%f", &value);
      printf("%.2f pounds is equal to %.2f kilograms.\n", value, value * 0.453);
      break;
    case 2:
      printf("Enter the number of feet: ");
      scanf("%f", &value);
      printf("%.2f feet is equal to %.2f meters.\n", value, value * 0.3048);
      break;
    default:
      printf("Invalid choice. Please choose either 1 or 2.\n");
      break;
  }
  
  printf("Thank you for using Medieval Converter!\n");

  return 0;
}