//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define COST_OF_TEA 10.0
#define COST_OF_COFFEE 20.0
#define COST_OF_PASTRY 15.0
#define TAX_RATE 0.1

int main()
{
    printf("Welcome to Cafe Java! \n");

    int numTeas, numCoffees, numPastries;

    printf("How many cups of tea would you like? ");
    scanf("%d", &numTeas);

    printf("How many cups of coffee would you like? ");
    scanf("%d", &numCoffees);

    printf("How many pastries would you like? ");
    scanf("%d", &numPastries);

    double subtotal = (numTeas * COST_OF_TEA) + (numCoffees * COST_OF_COFFEE) + (numPastries * COST_OF_PASTRY);
    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;

    printf("\n-------------------- Billing Details --------------------\n");
    printf("Item \t  Quantity \t  Cost \t  Total \n");
    printf("Tea \t  %d \t\t  $%.2f \t  $%.2f \n", numTeas, COST_OF_TEA, numTeas * COST_OF_TEA);
    printf("Coffee \t  %d \t\t  $%.2f \t  $%.2f \n", numCoffees, COST_OF_COFFEE, numCoffees * COST_OF_COFFEE);
    printf("Pastry \t  %d \t\t  $%.2f \t  $%.2f \n", numPastries, COST_OF_PASTRY, numPastries * COST_OF_PASTRY);
    printf("Total \t\t\t\t\t\t  $%.2f \n", subtotal);
    printf("Tax \t\t\t\t\t\t  $%.2f \n", tax);
    printf("Grand Total \t\t\t\t\t  $%.2f \n", total);

    printf("\nThank you for visiting Cafe Java! \n");

    return 0;
}