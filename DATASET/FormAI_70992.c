//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about customers
typedef struct {
    char name[50];
    char email[50];
    int age;
    float balance;
} Customer;

// Function to initialize a new customer
Customer create_customer(char name[], char email[], int age, float balance) {
    Customer customer;

    strcpy(customer.name, name);
    strcpy(customer.email, email);
    customer.age = age;
    customer.balance = balance;

    return customer;
}

// Function to print all customers in an array
void print_customers(Customer customers[], int num_customers) {
    printf("NAME\tEMAIL\tAGE\tBALANCE\n");

    for (int i = 0; i < num_customers; i++) {
        printf("%s\t%s\t%d\t$%.2f\n", customers[i].name, customers[i].email, customers[i].age, customers[i].balance);
    }
}

int main() {
    // Initial array of customers
    Customer customers[5];
    customers[0] = create_customer("Alice", "alice@gmail.com", 25, 100.0);
    customers[1] = create_customer("Bob", "bob@yahoo.com", 45, 500.0);
    customers[2] = create_customer("Charlie", "charlie@hotmail.com", 30, 250.0);
    customers[3] = create_customer("Dave", "dave@gmail.com", 60, 1000.0);
    customers[4] = create_customer("Eve", "eve@hotmail.com", 40, 750.0);

    // Print all customers
    printf("Initial Customers:\n");
    print_customers(customers, 5);

    // Query 1 - Print all customers with balance greater than $500
    printf("\nQuery 1 - Customers with balance > $500:\n");
    for (int i = 0; i < 5; i++) {
        if (customers[i].balance > 500.0) {
            printf("%s\t%s\t%d\t$%.2f\n", customers[i].name, customers[i].email, customers[i].age, customers[i].balance);
        }
    }

    // Query 2 - Print all customers with 'gmail' in their email address
    printf("\nQuery 2 - Customers with 'gmail' in email address:\n");
    for (int i = 0; i < 5; i++) {
        if (strstr(customers[i].email, "gmail") != NULL) {
            printf("%s\t%s\t%d\t$%.2f\n", customers[i].name, customers[i].email, customers[i].age, customers[i].balance);
        }
    }

    // Query 3 - Increase balances of all customers under 40 years old by 10%
    printf("\nQuery 3 - Customers under 40 years old with 10%% balance increase:\n");
    for (int i = 0; i < 5; i++) {
        if (customers[i].age < 40) {
            customers[i].balance *= 1.1;
            printf("%s\t%s\t%d\t$%.2f\n", customers[i].name, customers[i].email, customers[i].age, customers[i].balance);
        }
    }

    // Print all customers after changes
    printf("\nCustomers after changes:\n");
    print_customers(customers, 5);

    return 0;
}