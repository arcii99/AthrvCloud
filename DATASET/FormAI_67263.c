//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include <stdio.h>

// Function to calculate the total bill
float calculateBill(int quantity, float price) {
    float total = quantity * price;
    if (quantity >= 10 && quantity <= 20) {
        total *= 0.95; // 5% discount if quantity is between 10 and 20
    } else if (quantity > 20) {
        total *= 0.9; // 10% discount if quantity is greater than 20
    }
    return total;
}

int main() {
    char name[20];
    int quantity;
    float price, bill;

    printf("Welcome to Cafe Billing System!\n\n");

    // Get user input for name, quantity and price
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);
    printf("\n");

    // Calculate bill
    bill = calculateBill(quantity, price);

    // Display bill details
    printf("Bill details:\n");
    printf("Item name: %s\n", name);
    printf("Quantity: %d\n", quantity);
    printf("Price per unit: %.2f\n", price);
    printf("Total bill amount: %.2f\n", bill);

    return 0;
}