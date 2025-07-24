//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Prototype declaration of functions
float takeOrder();
void calculateBill(float);

// Global variables declaration
float totalPrice = 0.0, cost[5] = { 10.0, 20.0, 30.0, 15.0, 25.0 };
char items[5][20] = { "Coffee", "Tea", "Burger", "Pizza", "Sandwich" };

// Main function
int main() {
  printf("Welcome to the Cafe Billing System!\n\n");

  // Prompt user to take order
  float orderCost = takeOrder();

  // Calculate bill and display it to the user
  calculateBill(orderCost);

  return 0;
}

// Function to take the user's order
float takeOrder() {
  printf("Here's what we have on the menu:\n");
  printf("+----------------------------+\n");
  printf("| %-10s | %6s |\n", "Item", "Price");
  printf("+----------------------------+\n");

  // Display menu items and prices
  for (int i = 0; i < 5; i++) {
    printf("| %-10s | %6.2f |\n", items[i], cost[i]);
  }
  printf("+----------------------------+\n\n");

  // Prompt user to select items and quantity
  int choice, quantity;
  float itemCost, orderCost = 0.0;
  do {
    printf("Enter the item number you wish to order (1-5): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 5) {
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice < 1 || choice > 5);

  printf("Enter the quantity you wish to order: ");
  scanf("%d", &quantity);

  // Add the item cost to the total order cost
  itemCost = cost[choice - 1] * quantity;
  orderCost += itemCost;

  printf("\nYou have ordered %d %s.\n", quantity, items[choice - 1]);
  printf("The cost of your order is $%.2f.\n\n", itemCost);

  // Prompt user to add more items or finish order
  char answer;
  do {
    printf("Would you like to add more items to your order? (Y/N): ");
    scanf(" %c", &answer);

    switch (answer) {
      case 'Y':
      case 'y':
        orderCost += takeOrder();
        break;
      case 'N':
      case 'n':
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (answer != 'N' && answer != 'n' && answer != 'Y' && answer != 'y');

  return orderCost;
}

// Function to calculate and display the bill
void calculateBill(float orderCost) {
  printf("Here's your bill:\n");
  printf("+-----------------------------+\n");
  printf("| %-10s | %9s |\n", "Item", "Price");
  printf("+-----------------------------+\n");

  float tax = orderCost * 0.09;
  float totalCost = orderCost + tax;
  totalPrice += totalCost;

  // Display the item, quantity and cost for each order
  for (int i = 0; i < 5; i++) {
    if (cost[i] != 0.0) {
      printf("| %-10s | %6.2f |\n", items[i], cost[i]);
    }
  }
  printf("+-----------------------------+\n");
  printf("| %-10s | %6.2f |\n", "Subtotal", orderCost);
  printf("| %-10s | %6.2f |\n", "Tax", tax);
  printf("| %-10s | %6.2f |\n", "Total", totalCost);
  printf("+-----------------------------+\n\n");

  // Prompt user to generate a new bill or exit
  char answer;
  do {
    printf("Would you like to generate a new bill? (Y/N): ");
    scanf(" %c", &answer);

    switch (answer) {
      case 'Y':
      case 'y':
        printf("\n");
        calculateBill(takeOrder());
        break;
      case 'N':
      case 'n':
        printf("Thank you for using Cafe Billing System. Have a good day!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (answer != 'N' && answer != 'n' && answer != 'Y' && answer != 'y');
}