//FormAI DATASET v1.0 Category: Database querying ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Struct to hold details of a customer
typedef struct {
    int id;
    char name[50];
    char address[100];
    double balance;
} Customer;

// Function to query customers based on balance
Customer* queryCustomers(double minBalance, double maxBalance, int* numResults);

int main() {
    // Query customers with balance between $500 and $1000
    int numResults;
    Customer* results = queryCustomers(500, 1000, &numResults);

    // Print out the results
    printf("Found %d customers with balance between $500 and $1000:\n", numResults);
    for (int i = 0; i < numResults; i++) {
        printf("Customer #%d\n", results[i].id);
        printf("Name: %s\n", results[i].name);
        printf("Address: %s\n", results[i].address);
        printf("Balance: $%.2f\n", results[i].balance);
    }

    // Free the memory used by the results
    free(results);
    return 0;
}

Customer* queryCustomers(double minBalance, double maxBalance, int* numResults) {
    // Open the database file
    FILE* dbFile = fopen("customers.db", "r");

    // Initialize an array to hold the matching customers
    Customer* matchingCustomers = (Customer*) malloc(sizeof(Customer));

    // Read through the database file and find matching customers
    int numCustomers = 0;
    Customer currentCustomer;
    while (fread(&currentCustomer, sizeof(Customer), 1, dbFile)) {
        if (currentCustomer.balance >= minBalance && currentCustomer.balance <= maxBalance) {
            // Add the matching customer to the array
            numCustomers++;
            matchingCustomers = (Customer*) realloc(matchingCustomers, numCustomers * sizeof(Customer));
            matchingCustomers[numCustomers-1] = currentCustomer;
        }
    }

    // Close the database file
    fclose(dbFile);

    // Set the output parameter numResults
    *numResults = numCustomers;

    // Return the array of matching customers
    return matchingCustomers;
}