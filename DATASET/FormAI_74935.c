//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include<stdio.h>
#include<string.h>

// Function to calculate the bill for the customer
float calculateBill(int quantity, float price)
{
    float bill = quantity * price;
    if(quantity>=10) 
        bill *= 0.9;    // giving a 10% discount
    
    return bill;
}

int main()
{
    float price = 2.5; // Price of each item
    int quantity = 0; // Quantity of items purchased
    float bill = 0; // Total bill amount
    char itemName[20];

    printf("\nWelcome to our C Cafe Billing system!\n");
    printf("What would you like to order today? ");
    scanf("%s", itemName);

    printf("\nHow many %s(s) would you like to order? ", itemName);
    scanf("%d", &quantity);

    // Check if the quantity entered is valid
    while(quantity < 1)
    {
        printf("Please enter a valid quantity: ");
        scanf("%d", &quantity);
    }

    // Calculate the bill amount
    bill = calculateBill(quantity, price);

    // Display the bill to the customer
    printf("\nYour total bill amount for %d %s(s) is $%.2f\n", quantity, itemName, bill);
    printf("Thank you for choosing C Cafe! Have a nice day.\n");

    return 0;
}