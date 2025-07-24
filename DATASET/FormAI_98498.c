//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

struct menu_item {
    int item_id;
    char item_name[50];
    float item_price;
    int item_quantity;
};

typedef struct menu_item menu_item;

int main(void) {
    menu_item menu[10] = {
        { 1, "Coffee", 2.00, 0 },
        { 2, "Tea", 1.50, 0 },
        { 3, "Coke", 1.75, 0 },
        { 4, "Sandwich", 4.50, 0 },
        { 5, "French Fries", 3.00, 0 },
        { 6, "Burger", 5.00, 0 },
        { 7, "Pizza", 7.00, 0 },
        { 8, "Ice cream", 2.50, 0 },
        { 9, "Salad", 3.50, 0 },
        { 10, "Soup", 4.00, 0 }
    };
    
    float total = 0;
    int choice, quantity;
    
    printf("\nWelcome to our cafe! Please choose from our menu:\n");
    printf("ID      Name                Price\n");
    printf("==========================================\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%-2d  %-20s  $%-4.2f\n", menu[i].item_id, menu[i].item_name, menu[i].item_price);
    }
    
    while (1) {
        printf("\nEnter the ID of your item of choice (0 to quit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        for (int i = 0; i < 10; i++) {
            if (menu[i].item_id == choice) {
                printf("You have selected %s. How many would you like? ", menu[i].item_name);
                scanf("%d", &quantity);
                menu[i].item_quantity += quantity;
                total += menu[i].item_price * quantity;
            }
        }
    }
    
    printf("\nThank you for ordering at our cafe!\n");
    printf("Here is your bill:\n");
    printf("ID      Name                Price       Quantity\n");
    printf("=================================================\n");
    
    for (int i = 0; i < 10; i++) {
        if (menu[i].item_quantity > 0) {
            printf("%-2d  %-20s  $%-4.2f      %-2d\n", menu[i].item_id, menu[i].item_name, menu[i].item_price, menu[i].item_quantity);
        }
    }
    
    printf("-------------------------------------------------\n");
    printf("Your total bill is $%.2f\n", total);
    
    return 0;
}