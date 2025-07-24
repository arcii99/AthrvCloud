//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num_of_customers, i;
    float price, total_cost = 0, discount = 0, net_cost = 0;

    printf("Enter the total number of customers: ");
    scanf("%d", &num_of_customers);

    for (i = 1; i <= num_of_customers; i++)
    {
        printf("\nEnter the price of the order for customer %d: ", i);
        scanf("%f", &price);

        total_cost += price; // add the price to the total cost

        if (total_cost >= 10000) // apply 10% discount if total cost is greater than or equal to 10000
        {
            discount = 0.1 * total_cost;
            net_cost = total_cost - discount;
        }
        else
        {
            net_cost = total_cost;
        }

        printf("\nCustomer %d:\n", i);
        printf("Price of the order: %.2f\n", price);
        printf("Total cost: %.2f\n", total_cost);
        printf("Discount: %.2f\n", discount);
        printf("Net cost: %.2f\n", net_cost);
    }
}