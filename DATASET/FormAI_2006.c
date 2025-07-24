//FormAI DATASET v1.0 Category: Expense Tracker ; Style: calm
#include<stdio.h>
#include<stdlib.h>

int main(){

    int choice, amount, balance = 0;
    char ans;

    do{
        printf("Welcome to Expense Tracker App\n");
        printf("1. Add Expense\n");
        printf("2. View Balance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: //Add Expense
                printf("Enter Amount: ");
                scanf("%d",&amount);
                balance += amount;
                printf("Expense Added Successfully!\n\n");
                break;

            case 2: //View Balance
                printf("Balance: %d\n\n",balance);
                break;

            case 3: //Exit
                printf("Thank You for using Expense Tracker App!\n\n");
                exit(0);

            default:
                printf("Invalid Choice!\n\n");
        }

        printf("Do you want to continue? (y/n) ");
        scanf(" %c",&ans);

    }while(ans == 'y' || ans == 'Y');

    return 0;
}