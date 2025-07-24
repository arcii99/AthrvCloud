//FormAI DATASET v1.0 Category: Banking Record System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for bank account records
typedef struct {
    int account_number;
    char first_name[20];
    char last_name[20];
    double balance;
} BankAccount;

int main() {

    // create an array of bank account records
    BankAccount accounts[100];
    int num_accounts = 0;

    // loop for displaying and managing records
    int choice;
    do {
        // display menu options
        printf("C BANKING RECORD SYSTEM\n");
        printf("=======================\n");
        printf("1 - Add Account\n");
        printf("2 - Remove Account\n");
        printf("3 - View Account Details\n");
        printf("4 - Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // add account
                // get new account information
                BankAccount new_account;
                printf("\nEnter Account Number: ");
                scanf("%d", &new_account.account_number);
                printf("Enter First Name: ");
                scanf("%s", new_account.first_name);
                printf("Enter Last Name: ");
                scanf("%s", new_account.last_name);
                printf("Enter Balance: ");
                scanf("%lf", &new_account.balance);

                // add new account to array
                accounts[num_accounts] = new_account;
                num_accounts++;
                printf("\nAccount Added Successfully!\n");
                break;

            case 2: // remove account
                // get account number to remove
                int account_to_remove;
                printf("\nEnter Account Number to Remove: ");
                scanf("%d", &account_to_remove);

                // search for account and remove if found
                int found = 0;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].account_number == account_to_remove) {
                        // shift all accounts after this one down one index
                        for (int j = i + 1; j < num_accounts; j++) {
                            accounts[j-1] = accounts[j];
                        }
                        num_accounts--;
                        found = 1;
                        printf("\nAccount Removed Successfully!\n");
                        break;
                    }
                }
                if (!found) {
                    printf("\nAccount Not Found!\n");
                }
                break;

            case 3: // view account details
                // get account number to view
                int account_to_view;
                printf("\nEnter Account Number to View: ");
                scanf("%d", &account_to_view);

                // search for account and display if found
                found = 0;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].account_number == account_to_view) {
                        printf("\nAccount Details:\n");
                        printf("Account Number: %d\n", accounts[i].account_number);
                        printf("First Name: %s\n", accounts[i].first_name);
                        printf("Last Name: %s\n", accounts[i].last_name);
                        printf("Balance: %.2lf\n", accounts[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nAccount Not Found!\n");
                }
                break;

            case 4: // exit program
                printf("\nGoodbye!\n");
                break;

            default: // invalid choice
                printf("\nInvalid Choice!\n");
                break;
        }

        // wait for user to press enter before clearing screen and displaying menu again
        printf("\nPress Enter to Continue...");
        while (getchar() != '\n');
        getchar();
        system("clear");

    } while (choice != 4);

    return 0;
}