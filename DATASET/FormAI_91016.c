//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>

int main() {
  float monthly_income, monthly_expenses;
  
  // get user input for monthly income and expenses
  printf("Enter your monthly income: ");
  scanf("%f", &monthly_income);
  
  printf("Enter your monthly expenses: ");
  scanf("%f", &monthly_expenses);
  
  // calculate and display savings
  float monthly_savings = monthly_income - monthly_expenses;
  printf("Monthly savings: %.2f\n", monthly_savings);
  
  // calculate and display yearly savings
  float yearly_savings = monthly_savings * 12;
  printf("Yearly savings: %.2f\n", yearly_savings);
  
  // display recommended percentage breakdown for expenses
  printf("Recommended percentage breakdown for expenses:\n");
  printf("- Housing (30%%): $%.2f\n", monthly_income * 0.3);
  printf("- Food (15%%): $%.2f\n", monthly_income * 0.15);
  printf("- Transportation (10%%): $%.2f\n", monthly_income * 0.1);
  printf("- Entertainment (5%%): $%.2f\n", monthly_income * 0.05);
  printf("- Savings (20%%): $%.2f\n", monthly_income * 0.2);
  printf("- Other (20%%): $%.2f\n", monthly_income * 0.2);
  
  return 0;
}