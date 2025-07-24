//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h>

int main() {
  int currentAge;
  int retirementAge;
  float currentSalary;
  float monthlySavings;
  float annualExpenses;
  
  //Prompt user for input
  printf("Enter your current age: ");
  scanf("%d", &currentAge);
  
  printf("Enter your current salary: ");
  scanf("%f", &currentSalary);
  
  printf("Enter your monthly savings: ");
  scanf("%f", &monthlySavings);
  
  printf("Enter your annual expenses: ");
  scanf("%f", &annualExpenses);
  
  printf("Enter the age at which you plan to retire: ");
  scanf("%d", &retirementAge);
  
  //Calculate total savings
  float totalSavings = monthlySavings * 12 * (retirementAge - currentAge);
  
  //Calculate retirement income
  float retirementIncome = totalSavings * 0.05; //assume 5% return on investment
  
  //Calculate years of retirement income
  float retirementLength = (annualExpenses * 25) / retirementIncome; //assume 25 years of retirement
  
  //Calculate years until retirement
  int yearsUntilRetirement = retirementAge - currentAge;
  
  //Output results
  printf("\n--- PERSONAL FINANCE PLANNER ---\n");
  printf("Years until retirement: %d\n", yearsUntilRetirement);
  printf("Total savings until retirement: $%.2f\n", totalSavings);
  printf("Retirement income: $%.2f per year\n", retirementIncome);
  printf("Years of retirement income: %.2f years\n", retirementLength);
  
  return 0;
}