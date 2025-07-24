//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>

// declaring structures to store customer information and order details
struct customer {
    char name[30];
    int contact_no;
};

struct order {
    char item_name[20];
    int quantity;
    float amount;
};

int main() {
    int num_customers, num_orders;
    float total_amount = 0.0;

    printf("Enter the number of customers: ");
    scanf("%d", &num_customers);

    // creating an array of structures to store customer information
    struct customer customers[num_customers];

    // accepting customer information from the user
    for (int i = 0; i < num_customers; i++) {
        printf("\nEnter customer %d's name: ", i+1);
        scanf("%s", customers[i].name);

        printf("Enter customer %d's contact number: ", i+1);
        scanf("%d", &customers[i].contact_no);
    }

    // for each customer
    for (int i = 0; i < num_customers; i++) {
        printf("\n%s's orders", customers[i].name);
        printf("\nEnter the number of orders: ");
        scanf("%d", &num_orders);

        // creating an array of structures to store order details
        struct order orders[num_orders];

        // accepting order details from the user
        for (int j = 0; j < num_orders; j++) {
            printf("\nEnter item name for order %d: ", j+1);
            scanf("%s", orders[j].item_name);

            printf("Enter quantity for order %d: ", j+1);
            scanf("%d", &orders[j].quantity);

            printf("Enter amount for order %d: ", j+1);
            scanf("%f", &orders[j].amount);

            total_amount += orders[j].quantity * orders[j].amount;
        }

        // printing the customer's bill
        printf("\nBill for %s", customers[i].name);
        printf("\n------------------------------\n");
        printf("Item\t\tQuantity\tAmount\n");
        for (int j = 0; j < num_orders; j++) {
            printf("%s\t\t%d\t\t%.2f\n", orders[j].item_name, orders[j].quantity, orders[j].amount);
        }
        printf("\nTotal Amount: %.2f\n", total_amount);

        total_amount = 0.0;
    }

    return 0;
}