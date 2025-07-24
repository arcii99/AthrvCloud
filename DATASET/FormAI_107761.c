//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>

int main()
{
    float totalBill = 0;
    float burgerPrice = 3.99;
    float friesPrice = 1.99;
    float drinkPrice = 0.99;
    int burgerQty = 0;
    int friesQty = 0;
    int drinkQty = 0;

    printf("Welcome to the C Cafe!\n");

    // get number of burgers
    printf("How many burgers would you like to order? ");
    scanf("%d", &burgerQty);

    // get number of fries
    printf("How many fries would you like to order? ");
    scanf("%d", &friesQty);

    // get number of drinks
    printf("How many drinks would you like to order? ");
    scanf("%d", &drinkQty);

    // calculate total bill
    totalBill = (burgerPrice * burgerQty) + (friesPrice * friesQty) + (drinkPrice * drinkQty);

    printf("Your total bill is $%.2f\n", totalBill);

    printf("Thank you for dining at C Cafe!\n");

    return 0;
}