//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer{
    char name[50];
    int burger_count;
    int fries_count;
    int coke_count;
    float total_bill;
};

int main(){
    struct customer c;

    printf("Welcome to C Cafe!\n");
    printf("Please enter your name: ");
    fgets(c.name, 50, stdin);

    printf("How many burgers would you like?: ");
    scanf("%d", &c.burger_count);

    printf("How many orders of fries would you like?: ");
    scanf("%d", &c.fries_count);

    printf("How many cokes would you like?: ");
    scanf("%d", &c.coke_count);

    // calculate total bill
    float burger_price = 4.99;
    float fries_price = 2.99;
    float coke_price = 1.50;
    c.total_bill = (c.burger_count * burger_price) + (c.fries_count * fries_price) + (c.coke_count * coke_price);

    printf("\n\n***************************\n");
    printf("Here's your receipt, %s", c.name);
    printf("\n\nItem\t\tQuantity\t Price");
    printf("\n-------------------------------------------");
    printf("\nBurgers\t\t%d\t\t $%.2f", c.burger_count, (c.burger_count * burger_price));
    printf("\nFries\t\t%d\t\t $%.2f", c.fries_count, (c.fries_count * fries_price));
    printf("\nCokes\t\t%d\t\t $%.2f", c.coke_count, (c.coke_count * coke_price));
    printf("\n\n********************************");
    printf("\nTotal Bill:\t\t\t $%.2f", c.total_bill);
    printf("\n********************************\n\n");

    printf("Thank you for dining with us at C Cafe!");

    return 0;
}