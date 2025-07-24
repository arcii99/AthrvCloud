//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    float item1 = 3.50; //Price of the first item
    float item2 = 4.00; //Price of the second item
    float item3 = 2.50; //Price of the third item
    float total = 0.0; //Total bill
    int choice; //Menu item choice
    
    printf("Welcome to Oh So Sweet Cafe!\n");
    printf("Please take a look at our menu:\n");
    printf("1. Muffin - $%0.2f\n", item1);
    printf("2. Latte - $%0.2f\n", item2);
    printf("3. Croissant - $%0.2f\n", item3);

    //Ask for the user's menu item choice
    printf("What would you like to order? (1-3): ");
    scanf("%d", &choice);

    //Calculate the total bill based on the user's choice
    switch(choice) {
        case 1:
            total += item1; //Add the price of the first item to the total
            printf("\nYou ordered a muffin! That's %0.2f dollars.\n", item1);
            break;
        case 2:
            total += item2; //Add the price of the second item to the total
            printf("\nYou ordered a latte! That's %0.2f dollars.\n", item2);
            break;
        case 3:
            total += item3; //Add the price of the third item to the total
            printf("\nYou ordered a croissant! That's %0.2f dollars.\n", item3);
            break;
        default:
            printf("\nInvalid choice! Please try again.");
            return 1;
    }

    //Print out the total bill
    printf("Your total bill is: %0.2f dollars.\n", total);

    return 0;
}