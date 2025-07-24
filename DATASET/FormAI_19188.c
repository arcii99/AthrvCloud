//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ITEMS 10
#define MAX_NAME_LEN 20
#define MAX_MENU_ITEM_LEN 50
#define MAX_ORDER_LEN 200
#define TAX_RATE 0.07

// Define structs
typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int numItems;
} Menu;

typedef struct {
    char order[MAX_ORDER_LEN];
    float total;
} Order;

// Function prototypes
void loadMenu(Menu *menu);
void addMenuItem(Menu *menu, char *name, float price);
void printMenu(Menu *menu);
Order takeOrder(Menu *menu);
void printOrder(Order *order);
float calculateTotal(Order *order);

// Main function
int main(void) {
  Menu menu;
  loadMenu(&menu);
  printMenu(&menu);
  Order order = takeOrder(&menu);
  printOrder(&order);
  float total = calculateTotal(&order);
  printf("Total: $%.2f\n", total);
  return 0;
}

// Load the menu items into the menu struct
void loadMenu(Menu *menu) {
  // Initialize the menu
  menu->numItems = 0;
  // Add menu items
  addMenuItem(menu, "Coffee", 1.99);
  addMenuItem(menu, "Cappuccino", 3.49);
  addMenuItem(menu, "Latte", 3.99);
  addMenuItem(menu, "Muffin", 2.99);
  addMenuItem(menu, "Croissant", 2.49);
  addMenuItem(menu, "Bagel", 1.99);
  addMenuItem(menu, "Breakfast Sandwich", 4.99);
  addMenuItem(menu, "Bacon, Egg, and Cheese", 3.99);
  addMenuItem(menu, "Ham and Swiss Croissant", 4.49);
  addMenuItem(menu, "Greek Yogurt", 2.99);
}

// Add a menu item to the menu struct
void addMenuItem(Menu *menu, char *name, float price) {
  // Add the item
  MenuItem item;
  strncpy(item.name, name, MAX_MENU_ITEM_LEN);
  item.price = price;
  menu->items[menu->numItems++] = item;
}

// Print the menu
void printMenu(Menu *menu) {
  printf("%-30s %10s\n", "Item", "Price");
  printf("----------------------------------------\n");
  for (int i = 0; i < menu->numItems; i++) {
      printf("%-30s $%8.2f\n", menu->items[i].name, menu->items[i].price);
  }
}

// Take the order from the customer
Order takeOrder(Menu *menu) {
  printf("Enter your order (one item per line, enter done to finish):\n");
  Order order;
  order.total = 0;
  order.order[0] = '\0';
  char input[MAX_MENU_ITEM_LEN];
  float total = 0;
  do {
      scanf("%s", input);
      if (strcmp(input, "done") == 0) {
          break;
      }
      for (int i = 0; i < menu->numItems; i++) {
          if (strcmp(input, menu->items[i].name) == 0) {
              strcat(order.order, input);
              strcat(order.order, "  $");
              char priceStr[10];
              sprintf(priceStr, "%.2f\n", menu->items[i].price);
              strcat(order.order, priceStr);
              order.total += menu->items[i].price;
              break;
          }
      }
  } while (1);
  return order;
}

// Print the order
void printOrder(Order *order) {
  printf("Order:\n%s", order->order);
}

// Calculate the total including tax
float calculateTotal(Order *order) {
  return order->total * (1.0 + TAX_RATE);
}