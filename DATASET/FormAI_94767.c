//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Customer information structure
typedef struct {
    char name[50];
    int order[10];
    int quantity[10];
    int num_items;
    float total;
} Customer;

// Function to calculate the total amount for the customer
void calculate_total(Customer* customer) {
    float total = 0.0;
    for (int i = 0; i < customer->num_items; i++) {
        int order = customer->order[i];
        int quantity = customer->quantity[i];
        float price;
        switch(order) {
            case 1:
                price = 3.50;
                break;
            case 2:
                price = 2.50;
                break;
            case 3:
                price = 1.75;
                break;
            case 4:
                price = 0.99;
                break;
            default:
                price = 0.0;
        }
        total += price * quantity;
    }
    customer->total = total;
}

int main() {
    int num_customers;
    printf("Enter the number of customers: ");
    scanf("%d", &num_customers);
    Customer customers[num_customers];
    for (int i = 0; i < num_customers; i++) {
        printf("Enter the name of customer %d: ", i+1);
        scanf("%s", customers[i].name);
        printf("Enter the number of items for customer %d: ", i+1);
        scanf("%d", &customers[i].num_items);
        for (int j = 0; j < customers[i].num_items; j++) {
            printf("Enter item %d (1-Coffee, 2-Tea, 3-Soda, 4-Pastry): ", j+1);
            scanf("%d", &customers[i].order[j]);
            printf("Enter quantity of item %d: ", j+1);
            scanf("%d", &customers[i].quantity[j]);
        }
        calculate_total(&customers[i]);
    }
    printf("Customer\tTotal Amount\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s\t%.2f\n", customers[i].name, customers[i].total);
    }
    return 0;
}