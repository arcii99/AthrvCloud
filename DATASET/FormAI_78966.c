//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    // Welcome Message
    printf("Welcome to the Quantum Cafe!\n");

    // Randomize Seed Value
    srand(time(NULL));

    // Menu Items
    char menu[10][30] = {"Interstellar Iced Coffee",
                         "Galactic Green Tea Latte",
                         "Nebula Nitro Cold Brew",
                         "Celestial Cinnamon Mocha",
                         "Supernova Salted Caramel Macchiato",
                         "Cosmic Cookie Frappuccino",
                         "Starlight Strawberry Smoothie",
                         "Astronomical Avocado Toast",
                         "Meteor Meatball Sandwich",
                         "Solar Sushi Roll"};

    // Prices of Menu Items
    float price[10] = {8.99, 7.99, 9.99, 10.99, 12.99, 6.99, 5.99, 11.99, 13.99, 14.99};

    // Bill Details
    float total = 0.0;
    int discountPercent = 0;
    float discountAmount = 0.0;
    float taxPercent = 12.0;
    float taxAmount = 0.0;

    // Order Details
    char order[50];
    char choice = 'y';

    // Order Loop
    while (choice == 'y') {

        printf("\n");
        // Display Menu
        printf("MENU:\n");
        printf("S.No.\tItem Name\t\tPrice\n");
        for (int i = 0; i < 10; i++) {
            printf("%d.\t%s\t\t%.2f\n", i+1, menu[i], price[i]);
        }

        int itemNo, quantity;
        printf("\n");
        printf("Enter item number to order: ");
        scanf("%d", &itemNo);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        total += price[itemNo - 1] * quantity;

        printf("\nDo you want to order anything else? (y/n): ");
        scanf(" %c", &choice);
    }

    // Bill Processing
    printf("\n");
    printf("Please provide the below details for generating the bill:\n");
    printf("Order ID: ");
    int orderId;
    scanf("%d", &orderId);

    char customerName[30];
    printf("Customer Name: ");
    scanf("%*c%[^\n]", customerName);

    char customerEmail[30];
    printf("Customer Email: ");
    scanf("%*c%[^\n]", customerEmail);

    char customerPhone[15];
    printf("Customer Phone: ");
    scanf("%*c%[^\n]", customerPhone);

    int isMember = rand() % 2;

    if (isMember) {
        printf("\nCongratulations! You are a lucky member of the Quantum Cafe!\nYou are entitled to a 10 percent discount on your bill!\n\n");
        discountPercent = 10;
    } else {
        printf("\nWe are sorry, but you are not a member of the Quantum Cafe.\nHowever, you can become a member by signing up on our website!\n\n");
    }

    discountAmount = total * discountPercent / 100.0;
    taxAmount = total * taxPercent / 100.0;

    // Bill Generation
    printf("=====================================================================\n");
    printf("                        QUANTUM CAFE BILLS                           \n");
    printf("=====================================================================\n\n");
    printf("Order ID: %d\n", orderId);
    printf("Customer Name: %s\n", customerName);
    printf("Customer Email: %s\n", customerEmail);
    printf("Customer Phone: %s\n", customerPhone);

    printf("\n---------------------------------------------------------------------\n");
    printf("No.\tItem Name\t\tQuantity\t\tPrice\n");
    for (int i = 0; i < 10; i++) {
        if (price[i] != 0) {
            printf("%d.\t%s\t\t%d\t\t\t%.2f\n", i+1, menu[i], rand() % 10 + 1, price[i]);
        }
    }

    printf("\nTotal: \t\t\t\t\t\t%.2f\n", total);
    printf("Discount: \t\t\t\t\t%.2f\n", discountAmount);
    printf("Tax: \t\t\t\t\t\t%.2f\n", taxAmount);
    printf("Grand Total: \t\t\t\t\t%.2f\n", total - discountAmount + taxAmount);

    printf("\nThank you for visiting Quantum Cafe! Please come again!\n\n");

    return 0;
}