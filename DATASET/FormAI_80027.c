//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>

// function prototypes
void display_menu();
float calculate_bill(int quantity, float price, float tax_rate);

int main() {
    int choice, quantity;
    float price, tax_rate, bill_total;
    printf("Welcome to the C Cafe!\n\n");
    
    // display menu
    display_menu();
    
    // get user input
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price per unit: ");
    scanf("%f", &price);
    printf("Enter tax rate in percentage: ");
    scanf("%f", &tax_rate);
    
    // calculate bill and display total
    bill_total = calculate_bill(quantity, price, tax_rate);
    printf("\nYour bill is %.2f\n", bill_total);
    
    return 0;
}

// function to display menu
void display_menu() {
    printf("MENU\n");
    printf("1. Coffee (Regular)\t\t$2.00\n");
    printf("2. Coffee (Special)\t\t$2.50\n");
    printf("3. Tea (Regular)\t\t$1.50\n");
    printf("4. Tea (Special)\t\t$2.00\n");
    printf("5. Cakes (Slice)\t\t$3.00\n");
    printf("6. Cakes (Whole)\t\t$20.00\n");
}

// function to calculate bill
float calculate_bill(int quantity, float price, float tax_rate) {
    float total_amount, tax_amount;
    total_amount = quantity * price;
    tax_amount = total_amount * tax_rate / 100;
    return total_amount + tax_amount;
}