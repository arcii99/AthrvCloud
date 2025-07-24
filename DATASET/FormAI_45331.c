//FormAI DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account{
    int acc_no;
    char name[50];
    float balance;
};

typedef struct account Account;

void init_accounts(Account *accounts, int num_accounts){
    for(int i=0; i<num_accounts; i++){
        accounts[i].acc_no = i+1;
        strcpy(accounts[i].name, "Student");
        accounts[i].balance = 0.0;
    }
}

void display_accounts(Account *accounts, int num_accounts){
    printf("\n---Account Information---\n");
    for(int i=0; i<num_accounts; i++){
        printf("Account Number: %d\n", accounts[i].acc_no);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: $%.2f\n", accounts[i].balance);
        printf("-------------------------\n");
    }
}

void deposit(Account *account){
    float amount;
    printf("Enter amount to be deposited: $");
    scanf("%f", &amount);
    account->balance += amount;
    printf("Deposited $%.2f successfully!\n", amount);
}

void withdraw(Account *account){
    float amount;
    printf("Enter amount to be withdrawn: $");
    scanf("%f", &amount);
    if(account->balance - amount < 0){
        printf("Transaction failed: Insufficient balance.\n");
    }
    else{
        account->balance -= amount;
        printf("Withdrawn $%.2f successfully!\n", amount);
    }
}

int main(){
    int num_accounts = 5;
    Account accounts[num_accounts];
    init_accounts(accounts, num_accounts);

    while(1){
        printf("\n---Welcome to the C Banking System---\n");
        printf("1. Display Account Information\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            display_accounts(accounts, num_accounts);
        }
        else if(choice == 2){
            int acc_no;
            printf("Enter account number: ");
            scanf("%d", &acc_no);
            if(acc_no < 1 || acc_no > num_accounts){
                printf("Invalid account number.\n");
            }
            else{
                deposit(&accounts[acc_no-1]);
            }
        }
        else if(choice == 3){
            int acc_no;
            printf("Enter account number: ");
            scanf("%d", &acc_no);
            if(acc_no < 1 || acc_no > num_accounts){
                printf("Invalid account number.\n");
            }
            else{
                withdraw(&accounts[acc_no-1]);
            }
        }
        else if(choice == 4){
            printf("Thank you for using C Banking System!\n");
            return 0;
        }
        else{
            printf("Invalid choice.\n");
        }
    }

    return 0;
}