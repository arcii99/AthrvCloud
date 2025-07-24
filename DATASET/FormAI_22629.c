//FormAI DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BankRecord {
    int account_number;
    char name[50];
    float balance;
};

int main() {
    int i, n;
    struct BankRecord b[1000];
    char temp_name[50]; //temporarily store name
    float temp_balance; //temporarily store balance
    int temp_account_number; //temporarily store account number
    int choice, account_number_to_search, account_number_to_update;
    float deposit_amount, withdrawal_amount;
    
    printf("Welcome to the Banking Record System!\n");
    while(1) {
        printf("\nChoose an operation:\n");
        printf("1. Add a new record\n");
        printf("2. View all records\n");
        printf("3. Search a record by account number\n");
        printf("4. Update a record\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter the details:\n");
                printf("Account Number: ");
                scanf("%d", &temp_account_number);
                printf("Name: ");
                scanf("%s", temp_name);
                printf("Balance: ");
                scanf("%f", &temp_balance);
                
                // add the new record to the array
                b[n].account_number = temp_account_number;
                strcpy(b[n].name, temp_name);
                b[n].balance = temp_balance;
                n++; // increment the number of records
                printf("Record has been added successfully!\n");
                break;
            case 2:
                printf("\nAll Records:\n");
                printf("Account Number\tName\t\tBalance\n");
                for(i=0; i<n; i++) {
                    printf("%d\t\t%s\t\t%.2f\n", b[i].account_number, b[i].name, b[i].balance);
                }
                break;
            case 3:
                printf("\nEnter the account number to search: ");
                scanf("%d", &account_number_to_search);
                for(i=0; i<n; i++) {
                    if(b[i].account_number == account_number_to_search) {
                        printf("Account Number: %d\nName: %s\nBalance: %.2f\n", b[i].account_number, b[i].name, b[i].balance);
                        break;
                    }
                }
                if(i == n) {
                    printf("Record not found.\n");
                }
                break;
            case 4:
                printf("\nEnter the account number to update: ");
                scanf("%d", &account_number_to_update);
                for(i=0; i<n; i++) {
                    if(b[i].account_number == account_number_to_update) {
                        printf("Account Number: %d\nName: %s\nBalance: %.2f\n", b[i].account_number, b[i].name, b[i].balance);                       
                        printf("Enter the amount to deposit: ");
                        scanf("%f", &deposit_amount);
                        b[i].balance += deposit_amount;
                        printf("Updated record:\n");
                        printf("Account Number: %d\nName: %s\nBalance: %.2f\n", b[i].account_number, b[i].name, b[i].balance);
                        break;
                    }
                }
                if(i == n) {
                    printf("Record not found.\n");
                }
                break;
            case 5:
                printf("\nThank you for using the Banking Record System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}