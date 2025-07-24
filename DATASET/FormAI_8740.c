//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include<stdio.h>

// Define necessary variables
int numOfItems = 0;
float pricePerItem = 0.0;
float totalPrice = 0.0;

// Main function
int main() {
    // Display welcome message and instructions
    printf("Welcome to the Cafe Billing System\n");
    printf("Please enter the number of items you ordered: ");
    scanf("%d", &numOfItems);
    printf("Please enter the price per item: ");
    scanf("%f", &pricePerItem);

    // Calculate the total price and display it
    totalPrice = numOfItems * pricePerItem;
    printf("Your total bill is: $%.2f\n", totalPrice);

    return 0;
}