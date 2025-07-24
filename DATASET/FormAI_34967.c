//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char menu[5][20] = {"Coffee", "Tea", "Muffin", "Bagel", "Sandwich"};
  int price[5] = {3, 2, 2, 2, 5};
  int quantity[5] = {0}, total = 0, choice, num_items = 5;
  char ch;

  do
  {
    printf("Welcome to our cafe! Please choose from our menu:\n");
    for(int i = 0; i < num_items; i++)
    {
      printf("%d. %s - $%d\n", i+1, menu[i], price[i]);
    }
    printf("6. Exit\n");

    scanf("%d", &choice);
    if(choice == 6)
    {
      printf("Thank you for visiting our cafe!\n");
      break;
    }
    if(choice < 1 || choice > num_items)
    {
      printf("Invalid choice! Please choose a valid option.\n");
      continue;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity[choice-1]);

    total += price[choice-1] * quantity[choice-1];

    printf("Do you want to order anything else? (y/n) ");
    scanf(" %c", &ch);
  } while(ch == 'y' || ch == 'Y');

  printf("\nTotal bill: $%d\n", total);

  return 0;
}