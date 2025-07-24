//FormAI DATASET v1.0 Category: Banking Record System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount{
    int accountNo;
    char holderName[50];
    float balance;
}accounts[100];

int numAccounts = 0;

void createAccount(){
    if(numAccounts < 100){
        struct BankAccount newAccount;

        printf("\nEnter Account Number: ");
        scanf("%d", &newAccount.accountNo);

        printf("\nEnter Account Holder Name: ");
        scanf("%s", newAccount.holderName);

        printf("\nEnter Opening Balance: ");
        scanf("%f", &newAccount.balance);

        accounts[numAccounts] = newAccount;
        numAccounts++;

        printf("\nAccount Successfully Created!\n");
    }else{
        printf("\nCannot Create Account - Maximum Accounts Reached.\n");
    }
}

void displayAccounts(){
    if(numAccounts == 0){
        printf("\nNo Accounts Found.\n");
    }else{
        printf("\nBank Accounts:\n");
        for(int i=0; i<numAccounts; i++){
            printf("%d\t%s\t\t%.2f\n", accounts[i].accountNo, accounts[i].holderName, accounts[i].balance);
        }
    }
}

void searchAccount(){
    int accountNo;
    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNo == accountNo){
            printf("\n%s\t\t%.2f", accounts[i].holderName, accounts[i].balance);
            return;
        }
    }

    printf("\nNo Account Found with Account Number: %d\n", accountNo);
}

void withdraw(){
    int accountNo;
    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNo == accountNo){
            float amount;
            printf("\nEnter Amount to be Withdrawn: ");
            scanf("%f", &amount);

            if(amount > accounts[i].balance){
                printf("\nInsufficient Balance.\n");
                return;
            }

            accounts[i].balance -= amount;
            printf("\nWithdrawal Successful! Available Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("\nNo Account Found with Account Number: %d\n", accountNo);
}

void deposit(){
    int accountNo;
    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    for(int i=0; i<numAccounts; i++){
        if(accounts[i].accountNo == accountNo){
            float amount;
            printf("\nEnter Amount to be Deposited: ");
            scanf("%f", &amount);

            accounts[i].balance += amount;
            printf("\nDeposit Successful! Available Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("\nNo Account Found with Account Number: %d\n", accountNo);
}

int main(){
    int choice;

    do{
        printf("\n****Banking Record System****\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Withdraw\n");
        printf("5. Deposit\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3: searchAccount(); break;
            case 4: withdraw(); break;
            case 5: deposit(); break;
            case 6: printf("\nExiting..."); break;
            default: printf("\nInvalid Choice!\n");
        }
    }while(choice != 6);

    return 0;
}