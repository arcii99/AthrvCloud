//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total bill
float calculate_bill(int quantity, float cost_per_item) {
    float total = quantity * cost_per_item;
    return total;
}

// Main function to execute the program
int main() {
    int choice, quantity;
    float cost_per_item, total;
    
    // Display the menu
    printf("\n########## C CAFE BILLING SYSTEM ##########\n\n");
    printf("1. Coffee - $3.50\n");
    printf("2. Sandwich - $5.00\n");
    printf("3. Salad - $7.00\n");
    printf("4. Cake - $4.00\n");
    printf("5. Quit\n\n");
    
    // Ask for user's choice
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    
    // Switch statement to handle user's choice
    switch(choice) {
        case 1:
            // Calculate bill for coffee
            printf("\nYou have chosen Coffee.\n");
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            cost_per_item = 3.50;
            total = calculate_bill(quantity, cost_per_item);
            printf("\nTotal bill: $%.2f\n", total);
            break;
            
        case 2:
            // Calculate bill for sandwich
            printf("\nYou have chosen Sandwich.\n");
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            cost_per_item = 5.00;
            total = calculate_bill(quantity, cost_per_item);
            printf("\nTotal bill: $%.2f\n", total);
            break;
            
        case 3:
            // Calculate bill for salad
            printf("\nYou have chosen Salad.\n");
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            cost_per_item = 7.00;
            total = calculate_bill(quantity, cost_per_item);
            printf("\nTotal bill: $%.2f\n", total);
            break;
            
        case 4:
            // Calculate bill for cake
            printf("\nYou have chosen Cake.\n");
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            cost_per_item = 4.00;
            total = calculate_bill(quantity, cost_per_item);
            printf("\nTotal bill: $%.2f\n", total);
            break;
            
        case 5:
            // Quit the program
            printf("\nThank you for using C Cafe Billing System! Have a nice day!\n");
            exit(0);
            break;
            
        default:
            // Invalid choice
            printf("\nInvalid choice! Please enter a valid choice (1-5).\n");
            break;
    }
    
    return 0;
}