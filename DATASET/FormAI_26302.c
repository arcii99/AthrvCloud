//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>
#include <math.h>

int main()
{
  float principle, rate, time, EMI = 0, interest;
  printf("Enter Principle Amount: ");
  scanf("%f", &principle);
  printf("Enter Annual Interest Rate: ");
  scanf("%f", &rate);
  printf("Enter Time Period in Years: ");
  scanf("%f", &time);

  // Monthly Interest Calculation
  interest = rate / (12 * 100);

  // Monthly EMI Calculation
  EMI = (principle * interest * pow(1 + interest, time * 12)) / (pow(1 + interest, time * 12) - 1);

  // Total Payments
  float TotalPayment = EMI * time * 12;

  printf("\nMonthly EMI Payment: %.2f\n", EMI);
  printf("Total Amount Paid: %.2f\n", TotalPayment);

  return 0;
}