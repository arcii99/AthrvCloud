//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000

struct Customer {
    int id;
    char name[50];
    double balance;
};

struct Bank {
    struct Customer customers[MAX_CUSTOMERS];
    int num_customers;
};

struct Bank myBank;

// Function to add a new customer to the bank's record
void addCustomer(int id, char name[], double balance) {
    if (myBank.num_customers >= MAX_CUSTOMERS) {
        printf("Error: Maximum number of customers reached!\n");
        return;
    }

    struct Customer newCustomer;
    newCustomer.id = id;
    strcpy(newCustomer.name, name);
    newCustomer.balance = balance;

    myBank.customers[myBank.num_customers] = newCustomer;
    myBank.num_customers++;
    printf("New customer added successfully!\n");
}

// Function to display all of the bank's customers
void displayAllCustomers() {
    printf("Customer ID\tName\t\tBalance\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < myBank.num_customers; i++) {
        printf("%d\t\t%s\t\t$%.2f\n", myBank.customers[i].id,
            myBank.customers[i].name, myBank.customers[i].balance);
    }
}

// Function to search for a customer by name
void searchCustomerByName(char name[]) {
    printf("Search Results:\n");
    printf("Customer ID\tName\t\tBalance\n");
    printf("----------------------------------------\n");

    int found = 0;
    for (int i = 0; i < myBank.num_customers; i++) {
        if (strcmp(myBank.customers[i].name, name) == 0) {
            printf("%d\t\t%s\t\t$%.2f\n", myBank.customers[i].id,
                myBank.customers[i].name, myBank.customers[i].balance);
            found = 1;
        }
    }

    if (!found) {
        printf("No results found for \"%s\"\n", name);
    }
}

// Function to search for a customer by ID
void searchCustomerById(int id) {
    printf("Search Results:\n");
    printf("Customer ID\tName\t\tBalance\n");
    printf("----------------------------------------\n");

    int found = 0;
    for (int i = 0; i < myBank.num_customers; i++) {
        if (myBank.customers[i].id == id) {
            printf("%d\t\t%s\t\t$%.2f\n", myBank.customers[i].id,
                myBank.customers[i].name, myBank.customers[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No results found for ID %d\n", id);
    }
}

// Function to remove a customer from the bank's record
void removeCustomer(int id) {
    int found = 0;
    for (int i = 0; i < myBank.num_customers; i++) {
        if (myBank.customers[i].id == id) {
            // Shift all customers after this one down one index
            for (int j = i; j < myBank.num_customers - 1; j++) {
                myBank.customers[j] = myBank.customers[j+1];
            }
            myBank.num_customers--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Customer with ID %d successfully removed!\n", id);
    }
    else {
        printf("No customer found with ID %d\n", id);
    }
}

int main() {
    myBank.num_customers = 0;

    addCustomer(1001, "Jane Smith", 1500.00);
    addCustomer(1002, "John Doe", 2500.00);
    addCustomer(1003, "Samuel Johnson", 1000.00);

    displayAllCustomers();

    searchCustomerByName("John Doe");

    searchCustomerById(1003);

    removeCustomer(1002);

    displayAllCustomers();

    return 0;
}