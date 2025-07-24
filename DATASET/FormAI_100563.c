//FormAI DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store the banking record of a customer
struct customer_record{
    int account_number;
    char name[50];
    float balance;
};

int main(){
    int num_of_customers;
    printf("Enter the number of customers: ");
    scanf("%d", &num_of_customers);
    
    //Creating an array of structures to store multiple customer records
    struct customer_record customer_list[num_of_customers];
    
    for(int i=0; i<num_of_customers; i++){
        printf("\nEnter account number for customer #%d: ", i+1);
        scanf("%d", &customer_list[i].account_number);
        printf("Enter name for customer #%d: ", i+1);
        scanf("%s", customer_list[i].name);
        printf("Enter balance for customer #%d: ", i+1);
        scanf("%f", &customer_list[i].balance);
    }
    
    //Displaying all the customer records
    printf("\n\n**********Customer Records**********\n\n");
    for(int i=0; i<num_of_customers; i++){
        printf("Account Number: %d, Name: %s, Balance: $%.2f\n", customer_list[i].account_number, customer_list[i].name, customer_list[i].balance);
    }
    
    return 0;
}