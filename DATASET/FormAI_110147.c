//FormAI DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for the database table
typedef struct {
    int id;
    char name[50];
    char email[50];
    int age;
} Customer;

// function to add customer to the table
void addCustomer(Customer *customers, int *numCustomers) {
    printf("Enter customer name: ");
    scanf("%s", customers[*numCustomers].name);
    printf("Enter customer email: ");
    scanf("%s", customers[*numCustomers].email);
    printf("Enter customer age: ");
    scanf("%d", &customers[*numCustomers].age);
    customers[*numCustomers].id = *numCustomers + 1;
    *numCustomers = *numCustomers + 1;
}

// function to display all customers
void displayCustomers(Customer *customers, int numCustomers) {
    printf("\nID\tName\t\tEmail\t\tAge\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%d\t%s\t\t%s\t\t%d\n", customers[i].id, customers[i].name, customers[i].email, customers[i].age);
    }
    printf("\n");
}

// function to search for customer by name
void searchByName(Customer *customers, int numCustomers) {
    char name[50];
    printf("Enter customer name: ");
    scanf("%s", name);
    for (int i = 0; i < numCustomers; i++) {
        if (strcmp(customers[i].name, name) == 0) {
            printf("\nID\tName\t\tEmail\t\tAge\n");
            printf("%d\t%s\t\t%s\t\t%d\n", customers[i].id, customers[i].name, customers[i].email, customers[i].age);
            printf("\n");
            return;
        }
    }
    printf("No customer found with name %s.\n", name);
}

int main() {
    int numCustomers = 0;
    Customer customers[100];

    // add some initial customers
    strcpy(customers[0].name, "John Smith");
    strcpy(customers[0].email, "john.smith@gmail.com");
    customers[0].age = 30;
    customers[0].id = 1;
    numCustomers++;

    strcpy(customers[1].name, "Jane Doe");
    strcpy(customers[1].email, "jane.doe@yahoo.com");
    customers[1].age = 25;
    customers[1].id = 2;
    numCustomers++;

    // menu loop
    int choice = 0;
    while (choice != 4) {
        printf("\n===== CUSTOMER DATABASE =====\n");
        printf("1. Add Customer\n2. Display Customers\n3. Search by Name\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer(customers, &numCustomers);
                break;
            case 2:
                displayCustomers(customers, numCustomers);
                break;
            case 3:
                searchByName(customers, numCustomers);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}