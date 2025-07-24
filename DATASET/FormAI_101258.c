//FormAI DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transaction {
    int transaction_id;
    char customer_name[50];
    char product_name[50];
    double amount;
};

int main() {
    struct transaction transactions[5];
    int i, j;

    // Adding transaction data
    transactions[0].transaction_id = 101;
    strcpy(transactions[0].customer_name, "John Doe");
    strcpy(transactions[0].product_name, "Samsung Galaxy S10");
    transactions[0].amount = 750.99;

    transactions[1].transaction_id = 102;
    strcpy(transactions[1].customer_name, "Jane Smith");
    strcpy(transactions[1].product_name, "Apple iPhone XR");
    transactions[1].amount = 899.00;

    transactions[2].transaction_id = 103;
    strcpy(transactions[2].customer_name, "Bob Johnson");
    strcpy(transactions[2].product_name, "LG OLED TV");
    transactions[2].amount = 1499.99;

    transactions[3].transaction_id = 104;
    strcpy(transactions[3].customer_name, "Sarah Lee");
    strcpy(transactions[3].product_name, "Amazon Echo");
    transactions[3].amount = 99.00;

    transactions[4].transaction_id = 105;
    strcpy(transactions[4].customer_name, "Tom Davis");
    strcpy(transactions[4].product_name, "Sony Playstation 5");
    transactions[4].amount = 499.99;

    printf("Transaction Data\n");
    printf("==================\n");
    for (i = 0; i < 5; i++) {
        printf("Transaction ID: %d\n", transactions[i].transaction_id);
        printf("Customer Name: %s\n", transactions[i].customer_name);
        printf("Product Name: %s\n", transactions[i].product_name);
        printf("Amount: %.2f\n", transactions[i].amount);
        printf("------------------\n");
    }

    // Data Mining
    double max_amount = transactions[0].amount;
    double min_amount = transactions[0].amount;
    char max_amount_product[50];
    char min_amount_product[50];

    for (j = 0; j < 5; j++) {
        if (transactions[j].amount > max_amount) {
            max_amount = transactions[j].amount;
            strcpy(max_amount_product, transactions[j].product_name);
        }

        if (transactions[j].amount < min_amount) {
            min_amount = transactions[j].amount;
            strcpy(min_amount_product, transactions[j].product_name);
        }
    }

    // Displaying Results
    printf("Data Mining Results\n");
    printf("====================\n");
    printf("Product with Maximum Amount: %s\n", max_amount_product);
    printf("Maximum Amount: %.2f\n", max_amount);
    printf("Product with Minimum Amount: %s\n", min_amount_product);
    printf("Minimum Amount: %.2f\n", min_amount);

    return 0;
}