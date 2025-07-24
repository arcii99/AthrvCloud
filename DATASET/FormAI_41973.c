//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>

// function declarations
void displayMenu();
void calculateSavings();
void calculateLoanPayments();
void calculateRetirementSavings();
void calculateInvestmentGrowth();

int main()
{
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                calculateSavings();
                break;
            case 2:
                calculateLoanPayments();
                break;
            case 3:
                calculateRetirementSavings();
                break;
            case 4:
                calculateInvestmentGrowth();
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n\n");
        }
    } while(choice != 0);

    return 0;
}

// function definitions
void displayMenu()
{
    printf("Personal Finance Planner\n");
    printf("------------------------\n");
    printf("1. Calculate Savings\n");
    printf("2. Calculate Loan Payments\n");
    printf("3. Calculate Retirement Savings\n");
    printf("4. Calculate Investment Growth\n");
    printf("0. Exit\n\n");
}

void calculateSavings()
{
    float current_savings, monthly_contribution, interest_rate;
    int years;

    printf("Calculate Savings\n");
    printf("-----------------\n");
    printf("Enter current savings: ");
    scanf("%f", &current_savings);

    printf("Enter monthly contribution: ");
    scanf("%f", &monthly_contribution);

    printf("Enter number of years: ");
    scanf("%d", &years);

    printf("Enter interest rate (in percent): ");
    scanf("%f", &interest_rate);

    // calculate the future value with compound interest formula
    float future_value = current_savings;
    for(int i = 0; i < years * 12; i++) {
        future_value += monthly_contribution;
        future_value *= 1 + interest_rate / (12 * 100);
    }

    printf("\nTotal savings after %d years: $%.2f\n\n", years, future_value);
}

void calculateLoanPayments()
{
    float principal, interest_rate, monthly_payment;
    int years;

    printf("Calculate Loan Payments\n");
    printf("----------------------\n");
    printf("Enter loan principal: ");
    scanf("%f", &principal);

    printf("Enter interest rate (in percent): ");
    scanf("%f", &interest_rate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    // calculate the monthly interest rate and total number of payments
    float monthly_interest_rate = interest_rate / (12 * 100);
    int total_payments = years * 12;

    // calculate the monthly payment with loan payment formula
    monthly_payment = principal * monthly_interest_rate / (1 - pow(1 + monthly_interest_rate, -total_payments));

    printf("\nMonthly payment: $%.2f\n", monthly_payment);
    printf("Total amount paid: $%.2f\n\n", monthly_payment * total_payments);
}

void calculateRetirementSavings()
{
    float current_savings, monthly_savings, interest_rate;
    int years, retirement_age;

    printf("Calculate Retirement Savings\n");
    printf("---------------------------\n");
    printf("Enter current savings: ");
    scanf("%f", &current_savings);

    printf("Enter monthly savings: ");
    scanf("%f", &monthly_savings);

    printf("Enter number of years until retirement: ");
    scanf("%d", &years);

    printf("Enter interest rate (in percent): ");
    scanf("%f", &interest_rate);

    printf("Enter desired retirement age: ");
    scanf("%d", &retirement_age);

    // calculate the future value with compound interest formula
    float future_value = current_savings;
    for(int i = 0; i < years * 12; i++) {
        future_value += monthly_savings;
        future_value *= 1 + interest_rate / (12 * 100);
    }

    printf("\nTotal savings at retirement age: $%.2f\n\n", future_value);
}

void calculateInvestmentGrowth()
{
    float principal, interest_rate, annual_contributions;
    int years;

    printf("Calculate Investment Growth\n");
    printf("--------------------------\n");
    printf("Enter initial investment: ");
    scanf("%f", &principal);

    printf("Enter annual interest rate (in percent): ");
    scanf("%f", &interest_rate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    printf("Enter annual contributions: ");
    scanf("%f", &annual_contributions);

    // calculate the future value with compound interest formula
    float future_value = principal;
    for(int i = 0; i < years; i++) {
        future_value += annual_contributions;
        future_value *= 1 + interest_rate / 100;
    }

    printf("\nTotal investment value after %d years: $%.2f\n\n", years, future_value);
}