//FormAI DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//Structure for storing customer data
struct customer {
    char name[20];
    char address[30];
    int acc_no;
    float balance;
} customers[MAX];

//Function to initialize customer data
void initialize() {
    for(int i = 0; i < MAX; i++) {
        customers[i].acc_no = -1;
        customers[i].balance = 0;
        strcpy(customers[i].name, "");
        strcpy(customers[i].address, "");
    }
}

//Function to add new customer to the system
void add_customer() {
    int i;
    for(i = 0; i < MAX; i++) {
        if(customers[i].acc_no == -1) {
            printf("Enter customer name: ");
            scanf("%s", customers[i].name);
            printf("Enter customer address: ");
            scanf("%s", customers[i].address);
            printf("Enter account number: ");
            scanf("%d", &customers[i].acc_no);
            printf("Enter initial balance: ");
            scanf("%f", &customers[i].balance);
            printf("Customer added successfully.\n");
            break;
        }
    }
    if(i == MAX) {
        printf("Customer limit exceeded. Cannot add more customers.\n");
    }
}

//Function to display details of a customer
void display_customer(int acc_no) {
    int i;
    for(i = 0; i < MAX; i++) {
        if(customers[i].acc_no == acc_no) {
            printf("Customer details:\n");
            printf("Name: %s\n", customers[i].name);
            printf("Address: %s\n", customers[i].address);
            printf("Account number: %d\n", customers[i].acc_no);
            printf("Balance: %.2f\n", customers[i].balance);
            break;
        }
    }
    if(i == MAX) {
        printf("Customer not found.\n");
    }
}

//Function to deposit or withdraw money from a customer account
void transaction(int acc_no, float amount, char type) {
    int i;
    for(i = 0; i < MAX; i++) {
        if(customers[i].acc_no == acc_no) {
            switch(type) {
                case 'd':
                    customers[i].balance += amount;
                    printf("Deposit successful. New balance is %.2f\n", customers[i].balance);
                    break;
                case 'w':
                    if(amount > customers[i].balance) {
                        printf("Insufficient balance.\n");
                        break;
                    }
                    customers[i].balance -= amount;
                    printf("Withdrawal successful. New balance is %.2f\n", customers[i].balance);
                    break;
                default:
                    printf("Invalid transaction type.\n");
                    break;
            }
            break;
        }
    }
    if(i == MAX) {
        printf("Customer not found.\n");
    }
}

//Main function for running the program
int main() {
    initialize();
    
    char choice;
    do {
        printf("\n--Banking Record System--\n");
        printf("1. Add Customer\n");
        printf("2. Display Customer\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        
        int acc_no;
        float amount;
        switch(choice) {
            case '1':
                add_customer();
                break;
            case '2':
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                display_customer(acc_no);
                break;
            case '3':
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                transaction(acc_no, amount, 'd');
                break;
            case '4':
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                transaction(acc_no, amount, 'w');
                break;
            case '5':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
        
    } while(1);
    
    return 0;
}