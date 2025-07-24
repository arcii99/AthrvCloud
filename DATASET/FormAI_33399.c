//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

struct billing {
    char name[50];
    int table_no;
    int totalPrice;
};

int main() {
    struct billing customer;
    printf("Welcome to our Cafe Billing System!\n\n");
    printf("Please enter your name: ");
    scanf("%[^\n]s", customer.name);
    printf("Please enter your table number: ");
    scanf("%d", &customer.table_no);
    printf("\n");

    int num_of_items, i;
    printf("How many items did you order? ");
    scanf("%d", &num_of_items);
    printf("\n");

    int total=0;
    char itemName[50];
    int itemPrice;
    for(i=0; i<num_of_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", itemName);
        printf("Enter the price of item %d: ", i+1);
        scanf("%d", &itemPrice);
        total += itemPrice;
        printf("\n");
    }

    customer.totalPrice = total;
    printf("Dear %s,\n\n", customer.name);
    printf("Your bill for the table number %d is %d.\n\n", customer.table_no, customer.totalPrice);

    printf("Thank you for choosing our Cafe. Have a wonderful day ahead!\n");

    return 0;
}