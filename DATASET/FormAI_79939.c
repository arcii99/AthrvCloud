//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: random
#include <stdio.h>

int main() {
  float principal, rate, time, emi;
  int choice;

  printf("Welcome to our Mortgage Calculator!\n");

  do {
    printf("\nPlease choose an option:\n");
    printf("1. Calculate Monthly EMI\n");
    printf("2. Calculate Total Payment\n");
    printf("3. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nPlease enter the Principal amount: ");
        scanf("%f", &principal);

        printf("Please enter the Rate of interest (per annum): ");
        scanf("%f", &rate);

        printf("Please enter the Time period (in years): ");
        scanf("%f", &time);

        rate /= 1200.0;
        time *= 12;

        emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);
        printf("\nEMI amount = %.2f\n", emi);
        break;

      case 2:
        printf("\nPlease enter the Principal amount: ");
        scanf("%f", &principal);

        printf("Please enter the Rate of interest (per annum): ");
        scanf("%f", &rate);

        printf("Please enter the Time period (in years): ");
        scanf("%f", &time);

        rate /= 1200.0;
        time *= 12;

        printf("\nTotal Payment = %.2f\n", emi * time);
        break;

      case 3:
        printf("\nThank you for using our Mortgage Calculator!\n");
        break;

      default:
        printf("\nInvalid option. Please try again.\n");
        break;
    }
  } while (choice != 3);

  return 0;
}