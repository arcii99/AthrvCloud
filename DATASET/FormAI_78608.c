//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main() {
  float principal, rate, time, emi, total_amt, interest_amt;
  int years, months;

  printf("Welcome to the futuristic Mortgage Calculator!\n\n");

  printf("Enter the principal amount: ");
  scanf("%f", &principal);

  printf("Enter the interest rate (per annum): ");
  scanf("%f", &rate);

  printf("Enter the loan term (in years): ");
  scanf("%d", &years);

  //Conversion of years to months
  months = years*12;

  //Conversion of annual rate to monthly rate
  rate = rate/(12*100);

  //Calculation of EMI
  emi = (principal * rate * pow(1+rate,months)) / (pow(1+rate,months) - 1);

  //Total amount to be paid
  total_amt = emi * months;

  //Interest amount to be paid
  interest_amt = total_amt - principal;

  //Output
  printf("\nThe monthly EMI is: %0.2f", emi);
  printf("\nThe total amount to be paid is: %0.2f", total_amt);
  printf("\nThe interest amount to be paid is: %0.2f", interest_amt);

  return 0;
}