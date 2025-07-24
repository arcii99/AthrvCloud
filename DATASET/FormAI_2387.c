//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>

// Function to calculate monthly repayments based on loan amount and interest rate
float calculateRepayments(float principal, float interestRate, int numYears){

    float monthlyRate = interestRate / (12 * 100);
    int numMonths = numYears * 12;
    float monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -numMonths));

    return monthlyPayment;
}

// Function to calculate compound interest earned on savings
float calculateInterest(float principal, float interestRate, int numYears){

    float compoundInterest = principal * pow(1 + (interestRate / 100),numYears);

    return compoundInterest - principal;
}

// Function to calculate net worth by subtracting liabilities from assets
float calculateNetWorth(float assets, float liabilities){

    return assets - liabilities;
}

int main(){

    // User input
    float salary;
    printf("What is your monthly salary? ");
    scanf("%f",&salary);

    float expenses;
    printf("What are your monthly expenses? ");
    scanf("%f",&expenses);

    float savings;
    printf("What is your current savings balance? ");
    scanf("%f",&savings);

    float loanAmount;
    printf("What is the amount of loan you need? ");
    scanf("%f",&loanAmount);

    float loanInterestRate;
    printf("What is the loan interest rate? ");
    scanf("%f",&loanInterestRate);

    int loanYears;
    printf("How many years will you take to repay the loan? ");
    scanf("%d",&loanYears);

    float mortgage;
    printf("What is your current mortgage balance? ");
    scanf("%f",&mortgage);

    float propertyValue;
    printf("What is the current value of your property? ");
    scanf("%f",&propertyValue);

    // Calculations
    float netIncome = salary - expenses;
    float monthlyRepayments = calculateRepayments(loanAmount, loanInterestRate, loanYears);
    float mortgageInterestRate = 3.5; // Assume fixed interest rate for mortgage
    float monthlyMortgagePayments = calculateRepayments(mortgage, mortgageInterestRate, 30);
    float equity = propertyValue - mortgage;
    float interestEarned = calculateInterest(savings, 2.5, 5); // Assume interest rate on savings account is 2.5%
    float assets = savings + equity;
    float liabilities = loanAmount + mortgage;

    float netWorth = calculateNetWorth(assets, liabilities);

    // Output
    printf("\n");
    printf("Monthly net income: $%.2f\n", netIncome);
    printf("Monthly loan repayments: $%.2f\n", monthlyRepayments);
    printf("Monthly mortgage payments: $%.2f\n", monthlyMortgagePayments);
    printf("Current equity in property: $%.2f\n", equity);
    printf("Interest earned on savings in 5 years: $%.2f\n", interestEarned);
    printf("Total assets: $%.2f\n", assets);
    printf("Total liabilities: $%.2f\n", liabilities);
    printf("Net worth: $%.2f\n", netWorth);

    return 0;
}