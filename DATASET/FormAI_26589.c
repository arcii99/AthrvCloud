//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>

struct bank_record {
    int account_number;
    char name[50];
    float balance;
};

int main() {
    int choice, i, j, found=0, acc;
    struct bank_record b[100];
    
    // initialize all balances to zero
    for(i=0; i<100; i++) {
        b[i].balance = 0.0;
    }
    
    do {
        // display menu
        printf("\nBanking Record System Menu\n");
        printf("1. Add Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Update Account\n");
        printf("5. Delete Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // perform action based on user choice
        switch(choice) {
            case 1:
                // add account
                for(i=0; i<100; i++) {
                    if(b[i].balance == 0.0) {
                        printf("Enter account number: ");
                        scanf("%d", &b[i].account_number);
                        printf("Enter name: ");
                        scanf("%s", b[i].name);
                        printf("Enter balance: ");
                        scanf("%f", &b[i].balance);
                        break;
                    }
                }
                if(i == 100) {
                    printf("Cannot add account. Maximum limit reached.\n");
                }
                break;
                
            case 2:
                // display all accounts
                printf("\nAll Accounts:\n");
                printf("Account Number\tName\tBalance\n");
                for(i=0; i<100; i++) {
                    if(b[i].balance != 0.0) {
                        printf("%d\t%s\t%.2f\n", b[i].account_number, b[i].name, b[i].balance);
                    }
                }
                break;
                
            case 3:
                // search account
                printf("Enter account number to search: ");
                scanf("%d", &acc);
                for(i=0; i<100; i++) {
                    if(b[i].account_number == acc) {
                        printf("Account Number\tName\tBalance\n");
                        printf("%d\t%s\t%.2f\n", b[i].account_number, b[i].name, b[i].balance);
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    printf("Account not found.\n");
                }
                break;
                
            case 4:
                // update account
                printf("Enter account number to update: ");
                scanf("%d", &acc);
                for(i=0; i<100; i++) {
                    if(b[i].account_number == acc) {
                        printf("Enter new name: ");
                        scanf("%s", b[i].name);
                        printf("Enter new balance: ");
                        scanf("%f", &b[i].balance);
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    printf("Account not found.\n");
                }
                break;
                
            case 5:
                // delete account
                printf("Enter account number to delete: ");
                scanf("%d", &acc);
                for(i=0; i<100; i++) {
                    if(b[i].account_number == acc) {
                        for(j=i; j<99; j++) {
                            b[j] = b[j+1];
                        }
                        printf("Account deleted.\n");
                        break;
                    }
                }
                if(i == 100) {
                    printf("Account not found.\n");
                }
                break;
                
            case 6:
                // exit program
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while(choice != 6);
    
    return 0;
}