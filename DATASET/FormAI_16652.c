//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Defining the maximum number of bank customers */
#define MAX_CUSTOMERS 100

/* Defining the structure for bank customer record */
typedef struct {
    char name[50];
    int account_number;
    char account_type[10];
    double balance;
} customer;

/* Initializing an array of customer structures */
customer customers[MAX_CUSTOMERS];

/* Defining the function to add a new customer */
void add_customer() {
    char name[50];
    int account_number;
    char account_type[10];
    double balance;

    /* Prompting the user to input customer details */
    printf("\nEnter the customer name: ");
    scanf("%s", name);

    printf("\nEnter the account number: ");
    scanf("%d", &account_number);

    printf("\nEnter the account type (saving/checking): ");
    scanf("%s", account_type);

    printf("\nEnter the opening balance: ");
    scanf("%lf", &balance);

    /* Initializing the new customer */
    customer new_customer = {
        .name = name,
        .account_number = account_number,
        .account_type = account_type,
        .balance = balance
    };

    /* Adding the new customer to the array of customers */
    int i = 0;
    while (strlen(customers[i].name) != 0) {
        i++;
    }

    if (i < MAX_CUSTOMERS) {
        customers[i] = new_customer;
        printf("\nCustomer added successfully!\n");
    } else {
        printf("\nError: Maximum number of customers reached!\n");
    }
}

/* Defining the function to search for a customer by name */
void search_customer() {
    char name[50];

    /* Prompting the user to input the customer name */
    printf("\nEnter the customer name: ");
    scanf("%s", name);

    /* Searching the array of customers for the customer name */
    int i = 0;
    bool found = false;

    while (strlen(customers[i].name) != 0) {
        if (strcmp(customers[i].name, name) == 0) {
            found = true;
            break;
        }
        
        i++;
    }

    if (found) {
        printf("\nCustomer details:\n");
        printf("Name: %s\n", customers[i].name);
        printf("Account number: %d\n", customers[i].account_number);
        printf("Account type: %s\n", customers[i].account_type);
        printf("Balance: %.2f\n", customers[i].balance);
    } else {
        printf("\nError: Customer not found!\n");
    }
}

/* Defining the function to update a customer record */
void update_customer() {
    int account_number;
    double new_balance;

    /* Prompting the user to input the account number and new balance */
    printf("\nEnter the account number: ");
    scanf("%d", &account_number);

    printf("\nEnter the new balance: ");
    scanf("%lf", &new_balance);

    /* Searching the array of customers for the account number */
    int i = 0;
    bool found = false;

    while (strlen(customers[i].name) != 0) {
        if (customers[i].account_number == account_number) {
            found = true;
            break;
        }
        
        i++;
    }

    if (found) {
        customers[i].balance = new_balance;
        printf("\nCustomer record updated successfully!\n");
    } else {
        printf("\nError: Account number not found!\n");
    }
}

/* Defining the function to display all customer records */
void display_customers() {
    /* Displaying the header of the customer records table */
    printf("\nCustomer records:\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|     Name     |   Account Number   |   Account Type  |  Balance |\n");
    printf("+-------------------------------------------------------------+\n");

    /* Displaying the details of each customer */
    int i = 0;

    while (strlen(customers[i].name) != 0) {
        printf("| %-12s | %-18d | %-14s | $%8.2f |\n", 
            customers[i].name, customers[i].account_number, customers[i].account_type, customers[i].balance);
        
        i++;
    }

    /* Displaying the footer of the customer records table */
    printf("+-------------------------------------------------------------+\n");
}

/* Defining the main function */
int main() {
    /* Initializing the array of customers */
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        customers[i].name[0] = '\0';
    }

    /* Displaying the menu of options */
    int choice;

    do {
        printf("\nBanking Record System\n");
        printf("1. Add a new customer\n");
        printf("2. Search for a customer by name\n");
        printf("3. Update a customer record\n");
        printf("4. Display all customer records\n");
        printf("5. Exit\n");

        /* Prompting the user to choose an option */
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        /* Taking the necessary action based on the user's choice */
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                search_customer();
                break;
            case 3:
                update_customer();
                break;
            case 4:
                display_customers();
                break;
            case 5:
                printf("\nThank you for using the Banking Record System!\n");
                break;
            default:
                printf("\nError: Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}