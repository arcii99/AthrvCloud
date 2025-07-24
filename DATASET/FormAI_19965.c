//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: immersive
#include <stdio.h>

int main() {
  float principle, rate, time, emi, inter;
  int ch;

  // Getting user input
  printf("Enter Principle Amount: ");
  scanf("%f", &principle);
  printf("Enter Rate of Interest: ");
  scanf("%f", &rate);
  printf("Enter Time (in years): ");
  scanf("%f", &time);

  do {
    printf("\nSelect an option below:\n");
    printf("1. Calculate EMI\n");
    printf("2. Calculate Interest\n");
    printf("3. Exit\n");
    scanf("%d", &ch);

    switch(ch) {
      case 1:
        // Calculating EMI
        rate = rate / (12 * 100); // monthly interest rate
        time = time * 12; // time in months

        emi = (principle * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);
        printf("EMI: %.2f\n", emi);
        break;
      case 2:
        // Calculating interest
        inter = (principle * rate * time) / 100;
        printf("Interest: %.2f\n", inter);
        break;
      case 3:
        printf("Thank you for using Mortgage calculator\n");
        exit(0);
      default:
        printf("Invalid option selected");
    }
  } while(ch != 3);

  return 0;
}