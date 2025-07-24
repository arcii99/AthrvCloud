//FormAI DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the customer
typedef struct {
    char name[50];
    char email[50];
    char address[200];
} customer;

// Define the struct for the mailing list
typedef struct {
    customer* customers;   // array of customers
    int count;             // number of customers in the array
    int max_count;         // maximum number of customers that can be stored in the array
} mailing_list;

// Function to add customer to mailing list
void add_customer(mailing_list* list, char* name, char* email, char* address) {
    if(list->count == list->max_count) {
        printf("Mailing list is full!\n");
        return;
    }
    customer new_customer;
    strcpy(new_customer.name, name);
    strcpy(new_customer.email, email);
    strcpy(new_customer.address, address);
    list->customers[list->count] = new_customer;
    list->count++;
    printf("Customer added to mailing list!\n");
}

// Function to view all customers in mailing list
void view_customers(mailing_list* list) {
    printf("Mailing List:\n");
    for(int i=0; i<list->count; i++) {
        printf("\nName: %s\nEmail: %s\nAddress: %s\n", list->customers[i].name, list->customers[i].email, list->customers[i].address);
    }
}

// Function to search for a customer in mailing list
void search_customer(mailing_list* list, char* name) {
    for(int i=0; i<list->count; i++) {
        if(strcmp(list->customers[i].name, name) == 0) {
            printf("\nName: %s\nEmail: %s\nAddress: %s\n", list->customers[i].name, list->customers[i].email, list->customers[i].address); 
            return;
        }
    }
    printf("Customer not found in mailing list!\n");
}

// Main function
int main() {
    // Create a mailing list
    mailing_list list;
    list.max_count = 100;
    list.count = 0;

    // Allocate memory for the array of customers
    list.customers = (customer*) malloc(list.max_count*sizeof(customer));

    // Add some customers to the mailing list
    add_customer(&list, "John Doe", "john.doe@example.com", "123 Main St, Anytown, USA");
    add_customer(&list, "Jane Smith", "jane.smith@example.com", "456 Elm St, Anytown, USA");

    // View all customers in mailing list
    view_customers(&list);

    // Search for a customer in mailing list
    search_customer(&list, "John Doe");

    // Free memory
    free(list.customers);

    return 0;
}