//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 100
#define MAX_ITEM_NAME 50

struct MenuItem {
    char name[MAX_ITEM_NAME];
    float price;
    int quantity;
};

struct Order {
    int orderNumber;
    struct MenuItem items[MAX_MENU_ITEMS];
    int itemCount;
    float totalCost;
};

void printMenu() {
    printf("1 - Add item to order\n");
    printf("2 - Remove item from order\n");
    printf("3 - View order\n");
    printf("4 - Checkout\n");
    printf("5 - Exit\n");
    printf("Enter option: ");
}

void printMenuItems(struct MenuItem menu[], int itemCount) {
    printf("Menu: \n");
    for(int i=0; i<itemCount; i++) {
        printf("%d. %s - %.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

int addMenuItem(struct MenuItem menu[], char name[], float price, int itemCount) {
    if(itemCount >= MAX_MENU_ITEMS) {
        printf("Maximum menu item limit reached.\n");
        return itemCount;
    }
    strcpy(menu[itemCount].name, name);
    menu[itemCount].price = price;
    itemCount++;
    return itemCount;
}

void printOrder(struct Order order) {
    printf("Order #%d\n", order.orderNumber);
    for(int i=0; i<order.itemCount; i++) {
        printf("%d x %s - %.2f\n", order.items[i].quantity, order.items[i].name, order.items[i].price);
    }
    printf("Total cost: %.2f\n", order.totalCost);
}

float calculateTotalCost(struct Order order) {
    float total = 0.0;
    for(int i=0; i<order.itemCount; i++) {
        total += order.items[i].price * order.items[i].quantity;
    }
    return total;
}

int main() {
    struct MenuItem menu[MAX_MENU_ITEMS];
    int itemCount = 0;
    
    // Add initial menu items
    itemCount = addMenuItem(menu, "Coffee", 2.00, itemCount);
    itemCount = addMenuItem(menu, "Croissant", 1.50, itemCount);
    itemCount = addMenuItem(menu, "Muffin", 1.75, itemCount);
    
    // Start order
    struct Order order;
    order.orderNumber = rand() % 10000 + 1; // Random order number between 1 and 10000
    order.totalCost = 0.0;
    order.itemCount = 0;
    
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Add item
                printMenuItems(menu, itemCount);
                int itemChoice;
                printf("Enter item number: ");
                scanf("%d", &itemChoice);
                if(itemChoice <= 0 || itemChoice > itemCount) {
                    printf("Invalid item number.\n");
                }
                else {
                    char name[MAX_ITEM_NAME];
                    float price;
                    int quantity;
                    strcpy(name, menu[itemChoice-1].name);
                    price = menu[itemChoice-1].price;
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    order.items[order.itemCount].quantity = quantity;
                    strcpy(order.items[order.itemCount].name, name);
                    order.items[order.itemCount].price = price;
                    order.itemCount++;
                    printf("%d x %s added to order.\n", quantity, name);
                }
                break;
            case 2: // Remove item
                if(order.itemCount == 0) {
                    printf("No items in the order yet.\n");
                }
                else {
                    printf("Order:\n");
                    for(int i=0; i<order.itemCount; i++) {
                        printf("%d. %s - %.2f\n", i+1, order.items[i].name, order.items[i].price);
                    }
                    int removeChoice;
                    printf("Enter item number to remove: ");
                    scanf("%d", &removeChoice);
                    if(removeChoice <= 0 || removeChoice > order.itemCount) {
                        printf("Invalid item number.\n");
                    }
                    else {
                        printf("%d x %s removed from order.\n", order.items[removeChoice-1].quantity, order.items[removeChoice-1].name);
                        for(int i=removeChoice-1; i<order.itemCount-1; i++) {
                            order.items[i] = order.items[i+1];
                        }
                        order.itemCount--;
                    }
                }
                break;
            case 3: // View order
                if(order.itemCount == 0) {
                    printf("No items in the order yet.\n");
                }
                else {
                    printOrder(order);
                }
                break;
            case 4: // Checkout
                if(order.itemCount == 0) {
                    printf("No items in the order yet.\n");
                }
                else {
                    order.totalCost = calculateTotalCost(order);
                    printf("Total cost: %.2f\n", order.totalCost);
                    printf("Thank you for your purchase!\n\n");
                    // Start new order
                    order.orderNumber = rand() % 10000 + 1; // Random order number between 1 and 10000
                    order.totalCost = 0.0;
                    order.itemCount = 0;
                }
                break;
            case 5: // Exit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}