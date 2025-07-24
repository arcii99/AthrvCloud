//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the House of Fun Mortgage Calculator!\n");
    printf("Enter your mortgage amount: ");
    double principal, interestRate, monthlyPayment;
    int years;
    if (scanf("%lf", &principal) != 1 || principal < 0) {
        printf("Error: Invalid amount!\n");
        return 1;
    }
    printf("Enter your mortgage term in years: ");
    if (scanf("%d", &years) != 1 || years < 0) {
        printf("Error: Invalid years!\n");
        return 1;
    }
    printf("Enter your interest rate: ");
    if (scanf("%lf", &interestRate) != 1 || interestRate < 0) {
        printf("Error: Invalid interest rate!\n");
        return 1;
    }
    monthlyPayment = principal * (interestRate / 1200) / (1 - pow(1 + (interestRate / 1200), -years * 12));
    printf("\n\nHOORAY! You are now a proud owner of a mortgage that you can never pay off!\n");
    printf("Your monthly payment will be: $%0.2lf\n", monthlyPayment);
    printf("");


    printf("Type in the number of times I should say congrats to you : ");
    int count;
    if (scanf("%d", &count) != 1 || count < 0) {
        printf("Error: Invalid count!\n");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        printf("CONGRATS!!! You just got yourself into a lifetime of debt!\n");
    }
    printf("");


    printf("Do you want to see a breakdown of your mortgage payments? (y/n): ");
    char answer;
    fflush(stdin);
    if (scanf("%c", &answer) != 1) {
        printf("Error: Invalid answer!\n");
        return 1;
    }
    if (answer == 'y') {
        printf("\n\nWOW! You really want to see how much more money you will owe!\n");
        double balance = principal;
        printf("Month\tBalance\t\tPayment\t\tInterest\tPrincipal\n");
        for (int month = 1; month <= years * 12; month++) {
            double monthlyInterest = balance * (interestRate / 1200);
            double monthlyPrincipal = monthlyPayment - monthlyInterest;
            balance -= monthlyPrincipal;
            printf("%d\t$%0.2lf\t$%0.2lf\t$%0.2lf\t\t$%0.2lf\n",
                month, balance, monthlyPayment, monthlyInterest, monthlyPrincipal);
        }
    }
    printf("\nThank you for using the House of Fun Mortgage Calculator! You can never leave!\n");
    printf("");

    return 0;
}