//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(0));
  
  float income = rand() % 5000 + 1000; // generate random income from $1000 to $5000
  float expenses = rand() % 3000 + 500; // generate random expenses from $500 to $3000
  float savings = income - expenses; // calculate savings
  
  printf("Welcome to the Surrealist Personal Finance Planner!\n");
  printf("Your random income for the month is: $%.2f\n", income);
  printf("Your random expenses for the month is: $%.2f\n", expenses);
  printf("Your savings for the month is: $%.2f\n", savings);
  
  if (savings < 0)
  {
    printf("Oh no! You spent more than you earned. It's time to rethink your expenses.\n");
  }
  else if (savings < 1000)
  {
    printf("You managed to save some money, but it's not enough. Let's try to save more next month.\n");
  }
  else if (savings < 2000)
  {
    printf("You're on the right track! Keep it up and you'll have a nice vacation fund soon.\n");
  }
  else if (savings < 3000)
  {
    printf("Wow, you're doing great! You might even be able to afford a down payment on a house soon.\n");
  }
  else if (savings < 4000)
  {
    printf("Holy cow, you're a money-saving machine! You can probably retire early if you keep this up.\n");
  }
  else
  {
    printf("This is surreal! You're saving more than most people make in a month. Maybe you should consider donating some of your wealth.\n");
  }
  
  return 0;
}