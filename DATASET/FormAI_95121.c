//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\n\n\nWelcome to your Personal Finance Planner! Let's get started.\n\n");

    float salary, expenses, savings;

    printf("What is your monthly salary after taxes?\n");
    scanf("%f", &salary);
    printf("\nGreat! Now let's move on to your monthly expenses.\n");
    printf("How much do you spend each month on rent/mortgage payments?\n");
    scanf("%f", &expenses);
    printf("\nThanks for letting us know! Lastly, how much do you typically save each month?\n");
    scanf("%f", &savings);
    printf("\nAwesome! Now let's calculate your monthly budget.\n\n");

    float budget = salary - expenses;

    printf("Your total monthly budget is: $%.2f\n\n", budget);

    if(budget > savings){
        printf("Congratulations! You have extra money to put towards savings each month. Your new monthly savings amount is: $%.2f\n\n", savings);
    }
    else if(budget == savings){
        printf("Your budget is perfectly balanced! You are saving the exact amount you set aside each month. Keep up the good work!\n\n");
    }
    else{
        printf("Uh-oh, it seems like you are spending more than you earn. We suggest re-evaluating your expenses and finding ways to increase your income.\n\n");
    }

    printf("Thank you for using your Personal Finance Planner. We hope to see you again soon!\n\n\n");

    return 0;
}