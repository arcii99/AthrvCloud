//FormAI DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>

int main()
{
  // print welcome message
  printf("Welcome to Brave Unit Converter App!\n");

  // declare variables for conversion
  double distance, weight;
  int choice;

  do {
    // display unit menu and prompt for choice
    printf("\nPlease choose a conversion option:\n");
    printf("1. Convert meters to feet\n");
    printf("2. Convert kilograms to pounds\n");
    printf("3. Quit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // prompt for distance in meters and convert to feet
        printf("Enter distance in meters: ");
        scanf("%lf", &distance);
        double feet = distance * 3.281;
        printf("%.2lf meters is equal to %.2lf feet.\n", distance, feet);
        break;
      case 2:
        // prompt for weight in kilograms and convert to pounds
        printf("Enter weight in kilograms: ");
        scanf("%lf", &weight);
        double pounds = weight * 2.205;
        printf("%.2lf kilograms is equal to %.2lf pounds.\n", weight, pounds);
        break;
      case 3:
        // exit program
        printf("Exiting Brave Unit Converter App. Goodbye!\n");
        return 0;
      default:
        // invalid choice
        printf("Invalid choice. Please try again.\n");
    }

  } while (choice != 3); // repeat menu until user chooses to quit

  return 0;
}