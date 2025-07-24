//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include <stdio.h>
#include <math.h>

int main() {
  float Principle, Rate, Time, EMI, Interest;
  int NMonths;

  printf("Enter the Principle Amount: ");
  scanf("%f", &Principle);

  printf("\nEnter the Interest Rate: ");
  scanf("%f", &Rate);

  printf("\nEnter the Time (in years): ");
  scanf("%f", &Time);

  printf("\nEnter the Number of Months of Loan: ");
  scanf("%d", &NMonths);

  Rate = Rate / (12 * 100);
  Time = Time * 12;

  EMI = (Principle * Rate * pow(1 + Rate, Time)) / (pow(1 + Rate, Time) - 1);
  Interest = (EMI * NMonths) - Principle;

  printf("\n=====================[Loan EMI and Interest]============================\n");

  printf("\nLoan EMI: %.2f\nInterest Paid: %.2f\n", EMI, Interest);

  printf("\n===================[Loan Schedule]==================\n");

  int i;
  float Balance = Principle;

  printf("#\tEMI\tPrincipal\tInterest\tBalance\n");

  for (i = 1; i <= NMonths; i++) {
    float MonthlyInterest = (Rate * Balance);
    float PrincipalPaid = (EMI - MonthlyInterest);
    Balance = (Balance - PrincipalPaid);

    printf("%d\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n", i, EMI, PrincipalPaid, MonthlyInterest, Balance);
  }

  return 0;
}