//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
#include <stdio.h>

int main()
{
  float salary, rent, food, transportation, shopping, savings;

  printf("Enter your monthly salary: ");
  scanf("%f", &salary);

  printf("Enter your monthly rent: ");
  scanf("%f", &rent);

  printf("Enter your monthly food expense: ");
  scanf("%f", &food);

  printf("Enter your monthly transportation expense: ");
  scanf("%f", &transportation);

  printf("Enter your monthly shopping expense: ");
  scanf("%f", &shopping);

  savings = salary - (rent + food + transportation + shopping);
  if(savings < 0)
  {
    printf("You are in debt. Please reduce your expenses.\n");
    savings = 0;
  }
  else
  {
    printf("Your monthly savings: $%.2f\n", savings);
  }

  printf("Your yearly savings: $%.2f\n", savings * 12);

  return 0;
}