//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the Surrealist Personal Finance Planner!\n\n");

    srand(time(NULL)); // initialize random seed

    int income = rand() % 10000 + 5000; // generate random income between $5000 and $15000
    int expenses = rand() % income/2; // generate random expenses between 0 and half of income
    int savings = income - expenses; // calculate savings

    printf("Your current monthly income: $%d\n", income);
    printf("Your current monthly expenses: $%d\n", expenses);
    printf("Your current monthly savings: $%d\n\n", savings);

    if (savings > 5000) {
        printf("You have been deemed a Surrealist Financial Master!\n");
    } else if (savings > 2500) {
        printf("Your financial situation is quite surreal!\n");
    } else {
        printf("Your financial situation is sadly lacking in surrealist qualities.\n");
    }

    printf("\nWould you like to generate a random surreal financial goal? (yes or no)\n");
    char answer[4];
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0) {
        char* goals[10] = {"Own a house made entirely out of cheese", "Retire to a life of seashell collecting", "Acquire a lifetime supply of rainbow-colored socks", "Travel the world on a unicycle", "Become a professional extreme napper", "Own a dragon as a pet", "Pay off the national debt with pocket change", "Invent a new currency based on cat pictures", "Hire a personal robot to do all financial planning for you", "Live in a house with doors that only open to alternate dimensions"};
        int index = rand() % 10;
        printf("\nYour surreal financial goal is: %s\n", goals[index]);
    } else {
        printf("\nYour loss! Maybe try again later.\n");
    }

    return 0;
}