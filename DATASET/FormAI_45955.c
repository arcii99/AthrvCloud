//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

float calculate_mortgage(int principal, float interest, int years) {
  float monthly_interest = (interest / 12) / 100;
  int months = years * 12;
  float mortgage = (principal * monthly_interest * pow(1 + monthly_interest, months)) / (pow(1 + monthly_interest, months) - 1);
  return mortgage;
}

int main() {
  printf("Welcome to the Mortgage Calculator!\n\n");

  // Get user inputs
  int principal;
  printf("Enter the principal amount: ");
  scanf("%d", &principal);

  float interest;
  printf("Enter the interest rate: ");
  scanf("%f", &interest);

  int years;
  printf("Enter the number of years: ");
  scanf("%d", &years);

  // Calculate mortgage
  float mortgage = calculate_mortgage(principal, interest, years);

  // Display result
  printf("\nYour monthly mortgage payment is $%.2f\n", mortgage);

  return 0;
}