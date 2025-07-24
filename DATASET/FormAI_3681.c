//FormAI DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>

int main() {
  printf("Welcome to our restaurant!\n\n");

  int menuOption;
  printf("Please select an option from our menu:\n");
  printf("1. Hamburger - $5\n");
  printf("2. Pizza - $8\n");
  printf("3. Salad - $4\n");
  scanf("%d", &menuOption);

  int amount;
  printf("How many would you like to order?\n");
  scanf("%d", &amount);

  switch (menuOption) {
    case 1: {
      double price = amount * 5.0;
      printf("You have ordered %d hamburgers. The total cost is $%.2f\n", amount, price);
      break;
    }
    case 2: {
      double price = amount * 8.0;
      printf("You have ordered %d pizzas. The total cost is $%.2f\n", amount, price);
      break;
    }
    case 3: {
      double price = amount * 4.0;
      printf("You have ordered %d salads. The total cost is $%.2f\n", amount, price);
      break;
    }
    default: {
      printf("Invalid menu option\n");
    }
  }

  printf("\nThank you for dining with us!\n");

  return 0;
}