//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Surreal C Cafe Billing System
  time_t t;
  srand((unsigned) time(&t));
  
  // Menu
  char menu_items[10][50] = {"A cup of invisible tea","A plate of burning ice-cream","A slice of square pizza","A burger made of clouds","A bowl of singing spaghetti","A bagel with a unicorn's horn","A drink of pixelated water","A salad from the moon","A sandwich of dry ice","A bowl of melting snowflakes"}; 
  float menu_prices[10] = {10.50, 15.00, 20.99, 18.50, 25.00, 12.75, 7.99, 22.00, 17.25, 30.50};
  
  // Variables for order
  int order_count = 0;
  char order_name[50];
  float order_total = 0.0;
  
  // Order loop
  while(1) {
    printf("\nWelcome to Surreal C Cafe, what would you like to order?\n");
    for (int i=0; i<10; i++) {
      printf("%d. %s ($%.2f)\n", i+1, menu_items[i], menu_prices[i]);
    }
    printf("Enter your choice (1-10): ");
    int choice;
    scanf("%d", &choice);
    while (choice < 1 || choice > 10) {
      printf("Invalid input, please choose a number between 1 and 10: ");
      scanf("%d", &choice);
    }
    printf("You have ordered '%s' for $%.2f\n", menu_items[choice-1], menu_prices[choice-1]);
    printf("How many would you like to order? ");
    int quantity;
    scanf("%d", &quantity);
    
    if (quantity > 0) {
      order_count += quantity;
      order_total += (menu_prices[choice-1] * quantity);
      sprintf(order_name, "%d x %s", quantity, menu_items[choice-1]);
      printf("%s has been added to your order.\n", order_name);
      printf("Would you like to order anything else? (y/n): ");
      char again;
      scanf(" %c", &again);
      if (again == 'n') {
        break;
      }
    }
  }
  
  // Order summary
  printf("\nThank you for ordering from Surreal C Cafe!\n");
  printf("Your order:\n");
  printf("%-50s %-10s %-10s\n", "ITEM", "QUANTITY", "PRICE");
  for (int i=0; i<50; i++) {
    printf("-");
  }
  printf("\n");
  
  // Random order numbers
  srand(time(NULL));
  int order_number = rand() % 100000;
  
  // Item output
  for (int i=0; i<10; i++) {
    if (strstr(order_name, menu_items[i])) {
      printf("%-50s %-10.2d $%.2f\n", menu_items[i], order_count, (menu_prices[i] * order_count));
    }
  }
  
  for (int i=0; i<50; i++) {
    printf("-");
  }
  
  printf("\n");
  printf("%-50s %-10s $%.2f\n", "TOTAL", "", order_total);
  printf("\n");
  printf("Your order number is %d\n", order_number);

  return 0;
}