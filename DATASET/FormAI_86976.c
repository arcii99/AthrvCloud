//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>

// Function to calculate the total cost of the order
float calculateTotalCost(int quantity, float unitPrice) {
    float totalCost = quantity * unitPrice;
    return totalCost;
}

// Function to print the invoice with order details and total cost
void printInvoice(int orderNum, char itemName[], int quantity, float unitPrice, float totalCost) {
    printf("\n------------ Cafe Billing System ------------\n\n");
    printf("Order Number: %d\n", orderNum);
    printf("Item: %s\n", itemName);
    printf("Quantity: %d\n", quantity);
    printf("Unit Price: Rs. %.2f\n", unitPrice);
    printf("Total Cost: Rs. %.2f\n\n", totalCost);
}

int main() {
    int orderNum, quantity;
    char itemName[20];
    float unitPrice, totalCost;

    // Taking input from the user
    printf("Enter Order Number: ");
    scanf("%d", &orderNum);
    printf("Enter Item Name: ");
    scanf("%s", itemName);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Unit Price: ");
    scanf("%f", &unitPrice);

    // Calculating total cost using calculateTotalCost() function
    totalCost = calculateTotalCost(quantity, unitPrice);

    // Printing invoice using printInvoice() function
    printInvoice(orderNum, itemName, quantity, unitPrice, totalCost);

    return 0;
}