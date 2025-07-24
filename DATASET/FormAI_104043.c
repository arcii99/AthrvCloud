//FormAI DATASET v1.0 Category: Data validation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int numItems = 0;
    float totalPrice = 0;
    
    printf("Welcome to the shopping cart program!\n\n");
    
    while (1) {
        
        // get item name from user
        char itemName[20];
        printf("Please enter the name of your item (20 chars or less): ");
        fgets(itemName, 20, stdin);
        
        // validate input
        for (int i = 0; i < 20; i++) {
            if (itemName[i] == '\n') {
                itemName[i] = '\0';
                break;
            }
            if (!isalpha(itemName[i]) && !isspace(itemName[i])) {
                printf("Invalid input. Please enter only letters and spaces\n\n");
                goto Continue;
            }
        }
        
        // get item price from user
        float itemPrice = 0;
        printf("Please enter the price of your item (ex: 12.99): ");
        scanf("%f", &itemPrice);
        
        // continue invalid input check
        if (itemPrice <= 0) {
            printf("Invalid input. Please enter a positive number\n\n");
            getchar(); // clear input buffer
            goto Continue;
        }
        
        // continue shopping?
        getchar(); // clear input buffer
        char choice;
        printf("Item added to cart. Continue shopping? (y/n): ");
        scanf("%c", &choice);
        if (choice == 'n' || choice == 'N') {
            printf("\nYou have %d items in your cart and your total is $%.2f\n", numItems, totalPrice);
            printf("Thank you for shopping with us!\n\n");
            return 0;
        }
        
        // update cart
        numItems++;
        totalPrice += itemPrice;
        printf("\n");
        
        // continue loop
        Continue:
        continue;
    }
}