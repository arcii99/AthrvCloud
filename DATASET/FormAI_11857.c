//FormAI DATASET v1.0 Category: Data mining ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold customer information
typedef struct {
    char name[50];
    int age;
    char address[100];
    float balance;
} Customer;

int main() {
    // Initialize array of customers
    Customer customers[5] = {
        {"John Smith", 31, "123 Main St, Anytown USA", 100.50},
        {"Jane Doe", 25, "456 Elm St, Anycity USA", 500.00},
        {"Bob Johnson", 42, "789 Oak St, Anothercity USA", 750.25},
        {"Sarah Lee", 29, "321 Pine St, Somewhere USA", 45.75},
        {"Mike Chen", 38, "654 Maple St, Anywhere USA", 1000.00}
    };

    // Print all customer information
    printf("All customers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s\n", customers[i].name);
        printf("Age: %d\n", customers[i].age);
        printf("Address: %s\n", customers[i].address);
        printf("Balance: $%.2f\n\n", customers[i].balance);
    }

    // Find average age of customers
    int sum_age = 0;
    for (int i = 0; i < 5; i++) {
        sum_age += customers[i].age;
    }
    float avg_age = (float) sum_age / 5;
    printf("Average age of customers: %.1f\n\n", avg_age);

    // Find customer with highest balance
    Customer max_balance = customers[0];
    for (int i = 1; i < 5; i++) {
        if (customers[i].balance > max_balance.balance) {
            max_balance = customers[i];
        }
    }
    printf("Customer with highest balance:\n");
    printf("Name: %s\n", max_balance.name);
    printf("Age: %d\n", max_balance.age);
    printf("Address: %s\n", max_balance.address);
    printf("Balance: $%.2f\n\n", max_balance.balance);

    // Find customers with balance over $500
    printf("Customers with balance over $500:\n");
    for (int i = 0; i < 5; i++) {
        if (customers[i].balance > 500.00) {
            printf("Name: %s\n", customers[i].name);
            printf("Age: %d\n", customers[i].age);
            printf("Address: %s\n", customers[i].address);
            printf("Balance: $%.2f\n\n", customers[i].balance);
        }
    }

    return 0;
}