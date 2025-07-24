//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: inquisitive
#include<math.h>
#include<stdio.h>

int main()
{
    float principal, rate, time, emi, numerator, denominator, temp;

    printf("Welcome to Mortgage Calculator!\n");
    printf("Please enter the loan amount (in dollars): ");
    scanf("%f", &principal);
    printf("What is the yearly interest rate (in percentage)? ");
    scanf("%f", &rate);
    printf("How many years will you take to repay the loan? ");
    scanf("%f", &time);

    rate = rate / (12 * 100);
    time = time * 12;

    numerator = principal * rate;
    denominator = 1 - (pow(1 + rate, -time));
    emi = numerator / denominator;

    printf("The monthly payment is: $%.2f\n", emi);

    printf("Do you want to calculate the total interest paid over the entire loan term? (Y/N): ");
    char choice;
    scanf(" %c", &choice);

    switch(choice)
    {
        case 'Y':
        case 'y':
            printf("Calculating the total interest paid...\n");
            temp = emi * time - principal;
            printf("Total interest paid: $%.2f\n", temp);
            break;
        case 'N':
        case 'n':
            printf("Thank you for using Mortgage Calculator!\n");
            break;
        default:
            printf("Invalid input. Thank you for using Mortgage Calculator!\n");
            break;
    }

    return 0;
}