//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    int main(){
        int budget = 1000;
        int expense = 0;
        int savings = 0;
        char response[10];

        printf("Welcome to the Personal Finance Planner!\n");
        printf("Your starting budget is $1000. How much would you like to save? ");

        scanf("%d", &savings);

        while(savings < 0 || savings > budget){
            printf("Invalid amount. Please enter a value between 0 and %d: ", budget);
            scanf("%d", &savings);
        }

        budget -= savings;
        expense = budget / 4;

        printf("Great! You are now saving $%d, which means your monthly expense budget is $%d.\n", savings, expense);

        while(1){
            printf("\nEnter an expense (or type 'quit' to exit): ");
            scanf("%s", response);

            if(strcmp(response, "quit") == 0){
                printf("Thanks for using the Personal Finance Planner!\n");
                break;
            }

            int cost = atoi(response);

            if(cost > 0 && cost <= expense){
                printf("Expense approved! Your remaining budget is now $%d.\n", budget - cost);
                budget -= cost;
            } else {
                printf("Sorry, you cannot afford that expense. Your remaining budget is still $%d.\n", budget);
            }
        }

        return 0;
    }