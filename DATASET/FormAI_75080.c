//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Personal Finance Planner! Let's get started, shall we?\n\n");
    printf("Please enter your name:\n");
    char name[50];
    fgets(name, 50, stdin);
    printf("\n");
    printf("Hello %s, how much money do you have in your bank account?\n", name);
    float balance;
    scanf("%f", &balance);
    printf("\n");
    printf("Wow, %s, you must be rich! Now, let's get started planning your finances.\n", name);
    printf("\n");
    printf("What expenses do you have each month? Please enter them one by one (type 'done' to finish):\n");
    char expenses[10][50];
    int count = 0;
    float total = 0.0;
    while(1) {
        fgets(expenses[count], 50, stdin);
        if(strcmp(expenses[count], "done\n") == 0) {
            break;
        }
        count++;
    }
    printf("\n");
    for(int i = 0; i < count; i++) {
        printf("You have entered: %s", expenses[i]);
        printf("How much does %s cost each month?\n", expenses[i]);
        float cost;
        scanf("%f", &cost);
        total += cost;
    }
    printf("\n");
    float left = balance - total;
    if(left < 0) {
        printf("%s, you are in debt! You have spent %.2f more than you have in your bank account.\n", name, -left);
    } else {
        printf("%s, you are doing great! You have %.2f left in your bank account after paying for all your expenses.\n", name, left);
    }
    printf("\n");
    printf("Thanks for using the Personal Finance Planner! Have a great day! :)\n");

    return 0;
}