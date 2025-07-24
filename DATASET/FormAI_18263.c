//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int years;
  float principal, interest_rate, inflation_rate, monthly_savings, monthly_retirement_expenses;

  // Prompt user for input parameters
  printf("Enter number of years: ");
  scanf("%d", &years);

  printf("Enter principal amount: ");
  scanf("%f", &principal);

  printf("Enter annual interest rate (as a decimal): ");
  scanf("%f", &interest_rate);

  printf("Enter annual inflation rate (as a decimal): ");
  scanf("%f", &inflation_rate);

  printf("Enter monthly savings amount: ");
  scanf("%f", &monthly_savings);

  printf("Enter estimated monthly retirement expenses: ");
  scanf("%f", &monthly_retirement_expenses);

  // Calculate future value of principal with compound interest
  float compound_interest = pow(1 + interest_rate/12, 12) - 1;
  float future_principal = principal * pow(1 + (compound_interest), years);

  // Calculate future value of monthly savings with compound interest and inflation
  float future_savings = 0;
  for(int i=1; i<=years*12; i++){
    future_savings += monthly_savings * pow(1 + (interest_rate/12 - inflation_rate/12), i);
  }

  // Determine if user will reach retirement savings goal
  float retirement_savings_goal = 25 * monthly_retirement_expenses * 12;
  if(future_savings + future_principal >= retirement_savings_goal){
    printf("Congratulations! You will have enough savings to retire comfortably.\n");
  }
  else{
    printf("You will need to save more to reach your retirement goal.\n");
  }

  // Calculate average rate of return and standard deviation
  float average_return = pow(1 + interest_rate/12, 12) - 1;
  float std_dev = 0;
  for(int i=1; i<=years*12; i++){
    std_dev += pow((monthly_savings * pow(1 + (interest_rate/12 - inflation_rate/12), i))/future_savings - 1 - average_return, 2);
  }
  std_dev = sqrt(std_dev / (years*12));

  printf("Expected future value of principal: $%.2f\n", future_principal);
  printf("Expected future value of savings: $%.2f\n", future_savings);
  printf("Average rate of return: %.2f%%\n", average_return*100);
  printf("Standard deviation: %.2f\n", std_dev);

  return 0;
}