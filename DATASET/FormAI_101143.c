//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer { //structure to store details of customers
    char name[50];
    int tea_qty;
    int coffee_qty;
    int juice_qty;
    float bill;
};

void calc_bill(struct customer *c) { //function to calculate bill
    float tea_cost = 10.0, coffee_cost = 15.0, juice_cost = 20.0;
    c->bill = c->tea_qty * tea_cost + c->coffee_qty * coffee_cost + c->juice_qty * juice_cost;
}

int main() {
    int num_customers = 0;
    printf("Enter number of customers: ");
    scanf("%d", &num_customers);
    struct customer *customers = (struct customer*) malloc(num_customers * sizeof(struct customer));
    for(int i=0; i<num_customers; i++) {
        printf("\nEnter details of customer %d:\n", i+1);
        printf("Enter name: ");
        scanf("%s", customers[i].name);
        printf("Enter quantity of tea: ");
        scanf("%d", &customers[i].tea_qty);
        printf("Enter quantity of coffee: ");
        scanf("%d", &customers[i].coffee_qty);
        printf("Enter quantity of juice: ");
        scanf("%d", &customers[i].juice_qty);
        calc_bill(&customers[i]);
    }

    printf("\n\n%-20s%-20s%-20s%-20s%-20s\n", "Name", "Tea Quantity", "Coffee Quantity", "Juice Quantity", "Amount");
    for(int i=0; i<79; i++) {
        printf("-");
    }
    printf("\n");
    for(int i=0; i<num_customers; i++) {
        printf("%-20s%-20d%-20d%-20d%-20.2f\n", customers[i].name, customers[i].tea_qty, customers[i].coffee_qty, customers[i].juice_qty, customers[i].bill);
    }
    free(customers); // free memory
    return 0;
}