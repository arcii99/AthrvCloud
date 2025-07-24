//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>

int main() {
  double currentIncome, projectedIncome, monthlyExpenses, weeklyExpenses;
  
  printf("Welcome to your Personal Finance Planner!\n");
  
  printf("Please enter your current monthly income: $");
  scanf("%lf", &currentIncome);
  
  printf("Great! Now, please enter your projected monthly income: $");
  scanf("%lf", &projectedIncome);
  
  double totalIncome = currentIncome + projectedIncome;
  printf("Your total monthly income is: $%.2lf\n\n", totalIncome);
  
  printf("Next, we'll calculate your expenses.\n");
  
  printf("Please enter your monthly expenses: $");
  scanf("%lf", &monthlyExpenses);
  
  double dailyExpenses = monthlyExpenses / 30;
  double yearlyExpenses = monthlyExpenses * 12;
  
  printf("Your daily expenses are: $%.2lf\n", dailyExpenses);
  printf("Your yearly expenses are: $%.2lf\n\n", yearlyExpenses);
  
  printf("Now, let's calculate your weekly expenses.\n");
  
  printf("Please enter your weekly expenses: $");
  scanf("%lf", &weeklyExpenses);
  
  double weeklySavings = totalIncome / 4 - weeklyExpenses;
  double monthlySavings = weeklySavings * 4;
  
  printf("Your weekly savings are: $%.2lf\n", weeklySavings);
  printf("Your monthly savings are: $%.2lf\n\n", monthlySavings);
  
  double yearlySavings = monthlySavings * 12;
  double percentageSaved = monthlySavings / totalIncome * 100;
  
  printf("Your yearly savings are: $%.2lf\n", yearlySavings);
  printf("You're saving %.2lf%% of your total income each month.\n\n", percentageSaved);
  
  printf("Thanks for using your Personal Finance Planner!\n");
  
  return 0;
}