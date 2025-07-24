//FormAI DATASET v1.0 Category: Banking Record System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record{
    char name[30];
    char address[100];
    double balance;
} customer[100];

int main(){
    int number_of_customers;
    printf("Enter the number of customers: ");
    scanf("%d", &number_of_customers);
    getchar();

    for(int i=0; i<number_of_customers; i++){
        printf("\nEnter the details of customer %d:\n", i+1);

        printf("Name: ");
        fgets(customer[i].name, 30, stdin);
        strtok(customer[i].name, "\n");

        printf("Address: ");
        fgets(customer[i].address, 100, stdin);
        strtok(customer[i].address, "\n");

        printf("Balance: ");
        scanf("%lf", &customer[i].balance);
        getchar();
    }

    printf("\n==================== RECORDS ====================\n");
    printf("No.\tName\t\tAddress\t\t\tBalance\n");

    for(int j=0; j<number_of_customers; j++){
        printf("%d\t%-15s\t%-25s\t%.2lf\n", j+1, customer[j].name, customer[j].address, customer[j].balance);
    }

    printf("\n==================== BANKING RECORD SYSTEM SURPRISED ====================\n");
    printf("Wow! You have successfully recorded the data of %d customers in your banking record system.\n", number_of_customers);

    return 0;
}