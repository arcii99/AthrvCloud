//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MONTHS_IN_YEAR 12
#define PERCENTAGE_TO_DECIMAL(x) (x/100.0)

// Functions
void calculateLoanPayments(float loanAmount, float interestRate, int years);
void calculateSavings(float monthlyDeposit, float interestRate, int years);

int main()
{
    int quit = 0;
    while(!quit)
    {
        // Menu
        printf("Personal Finance Planner\n");
        printf("1. Calculate Loan Payments\n");
        printf("2. Calculate Savings\n");
        printf("3. Quit\n");

        // User input
        int option;
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                {
                    // Loan Payment Calculator
                    float loanAmount;
                    float interestRate;
                    int years;

                    printf("Loan Amount : ");
                    scanf("%f", &loanAmount);

                    printf("Interest Rate : ");
                    scanf("%f", &interestRate);

                    printf("Years : ");
                    scanf("%d", &years);

                    calculateLoanPayments(loanAmount, interestRate, years);
                    break;
                }

            case 2:
                {
                    // Savings Calculator
                    float monthlyDeposit;
                    float interestRate;
                    int years;

                    printf("Monthly Deposit : ");
                    scanf("%f", &monthlyDeposit);

                    printf("Interest Rate : ");
                    scanf("%f", &interestRate);

                    printf("Years : ");
                    scanf("%d", &years);

                    calculateSavings(monthlyDeposit, interestRate, years);
                    break;
                }

            case 3:
                {
                    // Quit
                    quit = 1;
                    break;
                }

            default:
                {
                    printf("Invalid option.\n");
                    break;
                }
        }

        // Wait for enter key to continue
        char c;
        scanf("%c", &c);
        printf("Press enter to continue...");
        getchar();
    }

    return 0;
}

// Function to calculate loan payments
void calculateLoanPayments(float loanAmount, float interestRate, int years)
{
    float ratePerMonth = PERCENTAGE_TO_DECIMAL(interestRate) / MONTHS_IN_YEAR;
    int totalMonthlyPayments = years * MONTHS_IN_YEAR;
    float monthlyPayment = (loanAmount * ratePerMonth) / (1 - pow(1 + ratePerMonth, -totalMonthlyPayments));

    printf("Monthly Payment : %.2f\n", monthlyPayment);
}

// Function to calculate savings
void calculateSavings(float monthlyDeposit, float interestRate, int years)
{
    float ratePerMonth = PERCENTAGE_TO_DECIMAL(interestRate) / MONTHS_IN_YEAR;
    int totalMonthlyPayments = years * MONTHS_IN_YEAR;
    float currentBalance = 0;

    for(int i = 0; i < totalMonthlyPayments; i++)
    {
        currentBalance = (currentBalance + monthlyDeposit) * (1 + ratePerMonth);
    }

    printf("Total Savings : %.2f\n", currentBalance);
}