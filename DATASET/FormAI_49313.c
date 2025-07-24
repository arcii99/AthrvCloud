//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  float principalAmount, rateOfInterest, tenure;
  printf("Enter principal amount: ");
  scanf("%f", &principalAmount);
  printf("Enter rate of interest (in percentage): ");
  scanf("%f", &rateOfInterest);
  printf("Enter tenure (in years): ");
  scanf("%f", &tenure);

  float interest = principalAmount * rateOfInterest * tenure / 100;
  float totalAmount = principalAmount + interest;
  int monthlyPayment = totalAmount / (tenure * 12);
  printf("Your total amount after %g years of taking the loan at %g%% interest rate is %g. Your monthly EMI is %d\n",tenure, rateOfInterest, totalAmount, monthlyPayment);

  printf("But what if your loan was not just a loan, but a magical beanstalk that grew so tall that it reaches the moon? \n");
  
  float moonPrincipalAmount = principalAmount * 238855; //Assuming 238855 miles is the distance to moon
  float moonInterest = moonPrincipalAmount * (rateOfInterest+10) / 100; //Magic interest rate
  float moonTotalAmount = moonPrincipalAmount + moonInterest;
  int moonMonthlyPayment = moonTotalAmount / (tenure * 1200); //Assuming one month on moon is 100 earth years

  printf("In that case, your principal amount becomes %g dollars, and your interest rate is %g%%. Your total amount after %g moon years is %g dollars.\n",moonPrincipalAmount, (rateOfInterest+10), tenure, moonTotalAmount);
  printf("And the best part? Your monthly EMI is only %d dollars!\n", moonMonthlyPayment);

  return 0;
}