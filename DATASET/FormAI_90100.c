//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INVESTMENT 50000
#define MIN_INVESTMENT 100
#define INTEREST_RATE 0.05

double calculate_final_amount(double principal_amount, double years) {
  double amount = principal_amount * pow((1 + INTEREST_RATE), years);
  return amount;
}

int main() {
  double investment_amount, years, final_amount;
  char choice;
  
  printf("Welcome to Personal Finance Planner!\n");
  
  do {
    printf("Enter your investment amount (minimum amount: $%d, maximum amount: $%d): ", MIN_INVESTMENT, MAX_INVESTMENT);
    scanf("%lf", &investment_amount);
    
    if (investment_amount < MIN_INVESTMENT || investment_amount > MAX_INVESTMENT) {
      printf("Invalid investment amount entered. Please try again.\n");
      continue;
    }
    
    printf("Enter the investment duration (in years): ");
    scanf("%lf", &years);
    
    final_amount = calculate_final_amount(investment_amount, years);
    
    printf("With an initial investment of $%.2lf and a %.2lf%% interest rate, your investment will grow to $%.2lf after %.0lf year(s)!\n", investment_amount, INTEREST_RATE * 100, final_amount, years);
    
    printf("Would you like to calculate for another investment? (Enter y for Yes or n for No): ");
    scanf(" %c", &choice);

  } while (choice == 'y' || choice == 'Y');
  
  printf("Thank you for using Personal Finance Planner!\n");
  
  return 0;
}