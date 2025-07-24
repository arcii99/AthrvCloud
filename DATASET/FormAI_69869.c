//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: puzzling
#include <stdio.h>

int main() {
  int principal, rate, time, interest;

  printf("Welcome to the Mortgage Calculator!\n");
  printf("To begin, please enter the principal amount: ");
  scanf("%d", &principal);
  printf("Great! Now enter the interest rate (in percentage): ");
  scanf("%d", &rate);
  printf("Almost done! Enter the time period (in years): ");
  scanf("%d", &time);

  // calculating interest
  interest = (principal * rate * time) / 100;

  printf("\nCalculating...\n");
  for (int i = 0; i <= 1000000000; i++) {
    if (i == 1000000000) {
      printf("Done!\n");
    }
  }

  printf("Your total interest payment is: %d\n", interest);
  printf("Your total mortgage amount is: %d\n", principal + interest);

  printf("\nThank you for using the Mortgage Calculator!");
  
  return 0;
}