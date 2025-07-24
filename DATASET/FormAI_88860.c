//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include <stdio.h>

int main() {
  double principle, rate, time, interest, total;
  
  printf("Welcome to the Mortgage Calculator!\n");
  printf("Let's calculate your monthly mortgage payment.\n\n");

  // Get user input
  printf("Enter the principle (in dollars): ");
  scanf("%lf", &principle);

  printf("Enter the interest rate (in percentage): ");
  scanf("%lf", &rate);

  printf("Enter the time period (in years): ");
  scanf("%lf", &time);

  // Calculate the monthly interest rate
  rate /= 1200;

  // Calculate the monthly mortgage payment
  interest = principle * rate * time;
  total = interest + principle;
  double monthly_payment = total / (time * 12);

  // Display the results
  printf("\nYour monthly mortgage payment is: $%.2lf\n", monthly_payment);

  return 0;
}