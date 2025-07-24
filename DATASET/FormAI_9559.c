//FormAI DATASET v1.0 Category: Banking Record System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bank_customer {
    char name[50];
    int account_number;
    double balance;
};

void print_customer(struct bank_customer customer) {
    printf("Name: %s\n", customer.name);
    printf("Account Number: %d\n", customer.account_number);
    printf("Balance: %lf\n", customer.balance);
}

void deposit(struct bank_customer *customer, double amount) {
    customer->balance += amount;
    printf("New balance for %s: %lf\n", customer->name, customer->balance);
}

void withdraw(struct bank_customer *customer, double amount) {
    if (customer->balance >= amount) {
        customer->balance -= amount;
        printf("New balance for %s: %lf\n", customer->name, customer->balance);
    } else {
        printf("Insufficient Balance!\n");
    }
}

int main() {
    struct bank_customer customer1 = {"John Doe", 12345, 1000.00};
    struct bank_customer customer2 = {"Jane Doe", 67890, 500.00};

    printf("Welcome to the Banking Record System!\n\n");

    print_customer(customer1);
    deposit(&customer1, 100.00);
    withdraw(&customer1, 200.00);

    printf("\n");

    print_customer(customer2);
    deposit(&customer2, 200.00);
    withdraw(&customer2, 700.00);

    printf("\n");

    return 0;
}