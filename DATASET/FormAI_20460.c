//FormAI DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000 //maximum number of transactions

int main(){
    float amount[MAX], balance=0;
    char type[MAX][15], date[MAX][11], choice;
    int i=0, num_transaction=0;

    printf("\n Expense Tracker "); 
    printf("\n------------------");

    do{
        printf("\nEnter details of transaction %d: ", i+1);
        printf("\nDate (dd/mm/yyyy): ");
        scanf("%s", date[i]);
        printf("Type (eg. Food): ");
        scanf("%s", type[i]);
        printf("Amount (in rupees): ");
        scanf("%f", &amount[i]);

        balance += amount[i];

        printf("\nTransaction recorded. ");
        printf("\nDo you want to add another transaction? (y for yes or n for no) ");
        scanf(" %c", &choice);
        i++;
        num_transaction++;
    }while(choice == 'y');

    printf("\n\n\t\tTransaction Details");
    printf("\n\t\t------------------");

    printf("\nDate\t\tType\t\tAmount (in rupees)\t\tBalance (in rupees)");
    printf("\n----\t\t----\t\t-----------------\t\t------------------");

    for(i=0; i<num_transaction; i++){
        printf("\n%s\t%s\t\t%.2f\t\t\t%.2f", date[i], type[i], amount[i], balance);
        balance -= amount[i];
    }

    printf("\n\n\t\t\tClosing Balance: Rs. %.2f\n", balance);

    return 0;
}