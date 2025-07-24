//FormAI DATASET v1.0 Category: Banking Record System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    int acc_number;
    char name[50];
    float balance;
};

void display_account(struct account ac){
    printf("\nAccount Number: %d", ac.acc_number);
    printf("\nName: %s", ac.name);
    printf("\nBalance: $%.2f", ac.balance);
}

void deposit(struct account *ac, float amount){
    ac->balance += amount;
    printf("\n$%.2f deposited successfully!", amount);
}

void withdraw(struct account *ac, float amount){
    if (ac->balance < amount){
        printf("\nWithdrawal failed, insufficient balance!");
    }else{
        ac->balance -= amount;
        printf("\n$%.2f withdrawn successfully!", amount);
    }
}

void transfer(struct account *from, struct account *to, float amount){
    if (from->balance < amount){
        printf("\nTransfer failed, insufficient balance!");
        return;
    }

    from->balance -= amount;
    to->balance += amount;

    printf("\n$%.2f transferred from Account %d to Account %d successfully!", amount, from->acc_number, to->acc_number);
}

int main(){
    struct account ac1, ac2;
    ac1.acc_number = 1001;
    strcpy(ac1.name, "Alice");
    ac1.balance = 1000.0;

    ac2.acc_number = 1002;
    strcpy(ac2.name, "Bob");
    ac2.balance = 500.0;

    printf("Initial Account Details:");
    display_account(ac1);
    display_account(ac2);

    // Shape-Shifting begins here

    printf("\n\n-------- Transaction 1: Deposit --------");
    printf("\nDeposit $500 to Account 1:");
    deposit(&ac1, 500.0);
    printf("\nUpdated Account Details:");
    display_account(ac1);

    printf("\n\n-------- Transaction 2: Withdraw --------");
    printf("\nWithdraw $400 from Account 2:");
    withdraw(&ac2, 400.0);
    printf("\nUpdated Account Details:");
    display_account(ac2);

    printf("\n\n-------- Transaction 3: Transfer --------");
    printf("\nTransfer $300 from Account 1 to Account 2:");
    transfer(&ac1, &ac2, 300.0);
    printf("\nUpdated Account Details:");
    display_account(ac1);
    display_account(ac2);

    return 0;
}