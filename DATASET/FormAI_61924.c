//FormAI DATASET v1.0 Category: Banking Record System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000

struct Account {
    int account_number;
    char holder_name[50];
    float balance;
};

struct Account bank_accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void create_account() {
    struct Account account;
    printf("\nCreating a new bank account...\n");

    printf("Enter account number: ");
    scanf("%d", &account.account_number);

    printf("Enter account holder name: ");
    scanf("%s", account.holder_name);

    printf("Enter account balance: ");
    scanf("%f", &account.balance);

    bank_accounts[num_accounts++] = account;

    printf("Account successfully created!\n");
}

void view_account() {
    int account_number;
    printf("\nViewing bank account...\n");

    printf("Enter account number: ");
    scanf("%d", &account_number);

    int i, found = 0;
    for (i=0; i<num_accounts; i++) {
        if (bank_accounts[i].account_number == account_number) {
            printf("Account holder name: %s\n", bank_accounts[i].holder_name);
            printf("Account balance: %.2f\n", bank_accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void update_account() {
    int account_number;
    printf("\nUpdating bank account...\n");

    printf("Enter account number: ");
    scanf("%d", &account_number);

    int i, found = 0;
    for (i=0; i<num_accounts; i++) {
        if (bank_accounts[i].account_number == account_number) {
            printf("Enter new account holder name: ");
            scanf("%s", bank_accounts[i].holder_name);

            printf("Enter new account balance: ");
            scanf("%f", &bank_accounts[i].balance);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    } else {
        printf("Account successfully updated!\n");
    }
}

void delete_account() {
    int account_number;
    printf("\nDeleting bank account...\n");

    printf("Enter account number: ");
    scanf("%d", &account_number);

    int i, found = 0;
    for (i=0; i<num_accounts; i++) {
        if (bank_accounts[i].account_number == account_number) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    } else {
        for (; i<num_accounts-1; i++) {
            bank_accounts[i] = bank_accounts[i+1];
        }
        num_accounts--;
        printf("Account successfully deleted!\n");
    }
}

void view_all_accounts() {
    int i;
    printf("\nViewing all bank accounts...\n");
    
    if (num_accounts == 0) {
        printf("No bank accounts found.\n");
    } else {
        for (i=0; i<num_accounts; i++) {
            printf("Account number: %d\n", bank_accounts[i].account_number);
            printf("Account holder name: %s\n", bank_accounts[i].holder_name);
            printf("Account balance: %.2f\n\n", bank_accounts[i].balance);
        }
    }
}

int main() {
    int option;
    do {
        printf("\nBank record system menu:\n");
        printf("1. Create account\n");
        printf("2. View account\n");
        printf("3. Update account\n");
        printf("4. Delete account\n");
        printf("5. View all accounts\n");
        printf("6. Exit\n");

        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                create_account();
                break;
            case 2:
                view_account();
                break;
            case 3:
                update_account();
                break;
            case 4:
                delete_account();
                break;
            case 5:
                view_all_accounts();
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option.\n");
        }

    } while(option != 6);

    return 0;
}