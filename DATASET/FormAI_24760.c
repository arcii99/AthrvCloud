//FormAI DATASET v1.0 Category: Banking Record System ; Style: funny
#include<stdio.h>
#include<string.h>

typedef struct {
    int account_number;
    char account_holder[50];
    float balance;
} Customer;

int main(){
    printf("Welcome to the Bank of Laughter!\n\n");
    printf("Our customer records are sure to make you giggle!\n\n");

    Customer customer_list[10];

    //Populate customer records with hilarious data
    customer_list[0].account_number = 1234;
    strcpy(customer_list[0].account_holder, "Barry McTickle");
    customer_list[0].balance = 5000.00;

    customer_list[1].account_number = 5678;
    strcpy(customer_list[1].account_holder, "Francois Funnypants");
    customer_list[1].balance = 8470.50;

    customer_list[2].account_number = 9101;
    strcpy(customer_list[2].account_holder, "Samantha Chuckleberry");
    customer_list[2].balance = 1200.00;

    customer_list[3].account_number = 2134;
    strcpy(customer_list[3].account_holder, "Bruce Gigglestein");
    customer_list[3].balance = 1630.75;

    customer_list[4].account_number = 8256;
    strcpy(customer_list[4].account_holder, "Lilly Laughalot");
    customer_list[4].balance = 650.00;

    customer_list[5].account_number = 4589;
    strcpy(customer_list[5].account_holder, "Geraldine Gigglesworth");
    customer_list[5].balance = 100000.00;

    customer_list[6].account_number = 3123;
    strcpy(customer_list[6].account_holder, "Harvey Heehee");
    customer_list[6].balance = 25000.00;

    customer_list[7].account_number = 7852;
    strcpy(customer_list[7].account_holder, "Oliver Chuckleneck");
    customer_list[7].balance = 357.00;

    customer_list[8].account_number = 6443;
    strcpy(customer_list[8].account_holder, "Maggie McJiggles");
    customer_list[8].balance = 6815.20;

    customer_list[9].account_number = 1012;
    strcpy(customer_list[9].account_holder, "George Guffaw");
    customer_list[9].balance = 75.50;

    //Display customer records
    printf("Customer Records:\n\n");
    printf("Account Number \tAccount Holder \t\tBalance\n");
    printf("------------------------------------------------------------------\n");

    for(int i=0; i<10; i++){
        printf("%d\t\t%s\t\t$%.2f\n", customer_list[i].account_number, customer_list[i].account_holder, customer_list[i].balance);
    }

    printf("\nThank you for banking with us! Keep laughing!\n");

    return 0;

}