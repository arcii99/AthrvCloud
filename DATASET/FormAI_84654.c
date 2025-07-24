//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdbool.h>

float menu[10][2] = {{1, 2.50}, {2, 3.00}, {3, 2.25}, {4, 4.25}, {5, 3.75}, {6, 1.75}, {7, 1.00}, {8, 0.50}, {9, 2.00}, {10, 1.50}};
char menu_items[10][25] = {"Coffee", "Tea", "Muffin", "Pizza", "Burger", "Donut", "Cookie", "Soda", "Sandwich", "Fries"};

float get_price(int item_code) {
    for(int i = 0; i < 10; i++) {
        if (menu[i][0] == item_code) {
            return menu[i][1];
        }
    }
    return -1;
}

int main() {
    printf("\n\nWelcome to C Cafe\n\n");
    printf("Here is our menu:\n\n");
    printf("Code\tName\t\tPrice\n");
    for (int i = 0; i < 10; i++) {
        printf("%.0f\t%s\t\t%.2f\n", menu[i][0], menu_items[i], menu[i][1]);
    }
    printf("\n\n");
    printf("Please enter the item code and quantity (separated by a space) for your order:\n");
    
    int item_code, quantity;
    bool valid_input = false;
    float price = 0;
    while (!valid_input) {
        scanf("%d %d", &item_code, &quantity);
        if (item_code < 1 || item_code > 10 || quantity < 1) {
            printf("Invalid input. Please enter a valid item code and quantity.\n");
        } else {
            valid_input = true;
            price = get_price(item_code) * quantity;
        }
    }
    
    printf("\n\n");
    printf("Order Summary:\n");
    printf("Quantity\tItem\t\tPrice\n");
    printf("%d\t\t%s\t\t%.2f\n", quantity, menu_items[item_code-1], price);
    
    printf("\n\nThank you for visiting C Cafe!\n\n");
    
    return 0;
}