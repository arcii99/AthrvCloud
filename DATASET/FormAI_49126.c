//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

// Structure to hold menu items
struct MenuItem {
    char name[50];
    int quantity;
    float price;
};

// Display menu function to display the menu items and their prices
void displayMenu(struct MenuItem menu[], int size) {
    printf("\n\n");
    for(int i=0; i<size; i++) {
        printf("%d\t%s\t\t\t%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("\n\n");
}

// Calculate total bill function to calculate the total bill based on the order
float calculateBill(struct MenuItem menu[], int order[], int size) {
    float bill = 0;
    printf("\n\n");
    for(int i=0; i<size; i++) {
        if(order[i]!=0) {
            printf("%s\t\t\t%d x %.2f = %.2f\n", menu[i].name, order[i], menu[i].price, order[i]*menu[i].price);
            bill += order[i]*menu[i].price;
            menu[i].quantity -= order[i];
        }
    }
    printf("\n\nTotal Bill: %.2f\n\n", bill);
    return bill;
}

int main() {
    // Initializing menu items
    struct MenuItem menu[5];
    strcpy(menu[0].name, "Black Coffee");
    menu[0].quantity = 10;
    menu[0].price = 2.50;
    strcpy(menu[1].name, "Latte");
    menu[1].quantity = 8;
    menu[1].price = 3.50;
    strcpy(menu[2].name, "Cappuccino");
    menu[2].quantity = 7;
    menu[2].price = 4.50;
    strcpy(menu[3].name, "Espresso");
    menu[3].quantity = 12;
    menu[3].price = 2.00;
    strcpy(menu[4].name, "Tea");
    menu[4].quantity = 15;
    menu[4].price = 1.50;

    // Displaying initial menu
    displayMenu(menu, 5);

    int size = sizeof(menu)/sizeof(menu[0]);
    int order[size];

    // Initializing order
    for(int i=0; i<size; i++) {
        order[i] = 0;
    }

    // Order loop
    char choice;
    do {
        printf("Enter Item Number to order: ");
        int item_number;
        scanf("%d", &item_number);
        if(item_number>0 && item_number<=size) {
            printf("Enter Quantity to order: ");
            int quantity;
            scanf("%d", &quantity);
            while(quantity<0 || quantity>menu[item_number-1].quantity) {
                printf("Invalid Quantity. Enter Quantity to order: ");
                scanf("%d", &quantity);
            }
            order[item_number-1] += quantity;
        } else {
            printf("Invalid Item Number\n");
        }
        printf("Do you want to order more items? (Y/N): ");
        scanf(" %c", &choice);
    } while(choice=='Y' || choice=='y');

    // Calculating and displaying the bill
    float bill = calculateBill(menu, order, size);

    // Displaying updated menu
    displayMenu(menu, size);

    return 0;
}