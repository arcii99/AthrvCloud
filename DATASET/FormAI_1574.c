//FormAI DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to hold customer information
typedef struct{
    char name[50];
    int accountNumber;
    double balance;
}customer;

//Function to deposit money
void deposit(customer *cust, double amount){
    cust->balance += amount;
    printf("Amount deposited: $%.2f\nNew balance: $%.2f\n", amount, cust->balance);
}

//Function to withdraw money
void withdraw(customer *cust, double amount){
    if(cust->balance >= amount){
        cust->balance -= amount;
        printf("Amount withdrawn: $%.2f\nNew balance: $%.2f\n", amount, cust->balance);
    }
    else{
        printf("Insufficient balance!\n");
    }
}

//Function to display customer information
void display(customer *cust){
    printf("Name: %s\nAccount Number: %d\nBalance: $%.2f\n", cust->name, cust->accountNumber, cust->balance);
}

int main(){

    customer c1, c2;

    //Customer 1
    strcpy(c1.name, "John Smith");
    c1.accountNumber = 12345;
    c1.balance = 1000.00;

    //Customer 2
    strcpy(c2.name, "Mary Johnson");
    c2.accountNumber = 54321;
    c2.balance = 500.00;

    //Deposit and withdraw money
    deposit(&c1, 500.00);
    withdraw(&c1, 200.00);

    //Display customer information
    display(&c1);

    deposit(&c2, 250.00);
    withdraw(&c2, 1000.00);

    display(&c2);

    return 0;
}