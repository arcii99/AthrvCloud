//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the C Cafe Billing System!\n");

    // Declare variables for billing process
    int drinks, food, total;
    float tax, final_total;

    // Request user input for number of drinks and food items
    printf("How many drinks did the customer order?\n");
    scanf("%d", &drinks);

    printf("How many food items did the customer order?\n");
    scanf("%d", &food);

    // Calculate the initial total (pre-tax)
    total = drinks * 3 + food * 7;

    printf("The initial total is: $%d\n", total);

    // Calculate the tax (8% of total) and final total (with tax)
    tax = total * 0.08;
    final_total = total + tax;

    printf("The tax is: $%.2f\n", tax);
    printf("The final total is: $%.2f\n", final_total);

    printf("Thank you for using the C Cafe Billing System!\n");

    return 0;
}