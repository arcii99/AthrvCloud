//FormAI DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_CUSTOMERS 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Customer;

int main() {
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;
    char input[100];
    
    while (1) {
        printf("Enter a command: ");
        fgets(input, 100, stdin);
        
        if (strcmp(input, "exit\n") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(input, "print\n") == 0) {
            printf("Customers:\n");
            
            for (int i = 0; i < num_customers; i++) {
                printf("%d. %s\n", i + 1, customers[i].name);
                printf("   %s\n", customers[i].address);
                printf("   %s\n", customers[i].phone);
            }
        } else if (strcmp(input, "add\n") == 0) {
            if (num_customers >= MAX_CUSTOMERS) {
                printf("Maximum number of customers reached!\n");
                continue;
            }
            
            Customer c;
            printf("Enter customer name: ");
            fgets(c.name, MAX_NAME_LENGTH, stdin);
            printf("Enter customer address: ");
            fgets(c.address, MAX_ADDRESS_LENGTH, stdin);
            printf("Enter customer phone number: ");
            fgets(c.phone, MAX_PHONE_LENGTH, stdin);
            
            customers[num_customers] = c;
            num_customers++;
            
            printf("Customer added!\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}