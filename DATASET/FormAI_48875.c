//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
#include <stdio.h>

int main() {
  double principal, rate, time, emi, total;
  
  printf("Enter the principal amount: ");
  scanf("%lf", &principal);

  printf("Enter the interest rate: ");
  scanf("%lf", &rate);

  printf("Enter the loan period in years: ");
  scanf("%lf", &time);

  /* Calculating EMI */
  rate = rate / (12 * 100); /* monthly interest rate */
  time = time * 12; /* months */
  emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

  /* Calculating Total Payment */
  total = emi * time;

  /* Displaying Results */
  printf("\n");
  printf("Principal Amount: $%.2lf\n", principal);
  printf("Interest Rate: %.2lf%%\n", rate * 100);
  printf("Loan Period: %.2lf years\n", time / 12);
  printf("EMI: $%.2lf\n", emi);
  printf("Total Payment: $%.2lf\n", total);

  return 0;
}