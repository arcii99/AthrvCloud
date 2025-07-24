//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main(){
  float principal, rate, emi, interest_per_month, balance;
  int term_years, term_months, total_term_months;
  printf("Enter principal amount:\n");
  scanf("%f", &principal);
  printf("Enter annual interest rate:\n");
  scanf("%f", &rate);
  printf("Enter the term in years and months:\n");
  scanf("%d %d", &term_years, &term_months);
  total_term_months = term_years * 12 + term_months;
  interest_per_month = rate / 1200;
  emi = principal * interest_per_month * pow((1+interest_per_month), total_term_months)/(pow((1+interest_per_month), total_term_months)-1);
  printf("EMI is: %.2f\n", emi);
  printf("Year\tInterest\tPrincipal\tBalance\n");
  for(int i=1; i<=total_term_months; i++){
    interest_per_month = balance * rate / 1200;
    balance += emi - interest_per_month;
    printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", (i-1)/12+1, interest_per_month, emi - interest_per_month, balance);
  }
  return 0;
}