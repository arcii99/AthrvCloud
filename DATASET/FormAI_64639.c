//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>

int main() {
  printf("Welcome to your Personal Finance Planner!\n");
  
  float salary, expenses, savings;
  printf("Please enter your monthly salary: ");
  scanf("%f", &salary);
  
  printf("Please enter your monthly expenses: ");
  scanf("%f", &expenses);
  
  savings = salary - expenses;
  
  if (savings < 0) {
    printf("Uh-oh, it looks like you are spending more than you earn!\n");
  } else if (savings == 0) {
    printf("You are breaking even every month - it's time to reevaluate your expenses!\n");
  } else {
    printf("Congratulations! You are saving $%.2f every month!\n", savings);
  }
  
  printf("Let's set some financial goals for the next six months.\n");
  
  float goal1, goal2, goal3;
  printf("Enter your first financial goal amount: ");
  scanf("%f", &goal1);
  
  printf("Enter your second financial goal amount: ");
  scanf("%f", &goal2);
  
  printf("Enter your third financial goal amount: ");
  scanf("%f", &goal3);
  
  float total_goals = goal1 + goal2 + goal3;
  float six_months = savings * 6;
  
  if (six_months < total_goals) {
    printf("Oh no! It looks like you may not be able to reach your financial goals in the next six months. Consider adjusting your expenses and increasing your savings.\n");
  } else if (six_months == total_goals) {
    printf("You are right on track to reaching your financial goals in the next six months - keep up the good work!\n");
  } else {
    printf("Congratulations! You are on track to exceeding your financial goals in the next six months!\n");
  }
  
  return 0;
}