//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment;
    int loan_term;

    printf("Welcome to Mortgage Calculator! \n");

    printf("Please enter the loan amount (in dollars): ");
    scanf("%f", &loan_amount);

    printf("Please enter the interest rate (in percentage): ");
    scanf("%f", &interest_rate);

    printf("Please enter the loan term (in months): ");
    scanf("%d", &loan_term);

    // calculate the monthly payment using formula
    float monthly_interest_rate = interest_rate / 1200.0;
    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - (1 / pow(1 + monthly_interest_rate, loan_term)));

    printf("Your Monthly Payment will be $%.2f \n", monthly_payment);
    
    printf("Would you like to see an Amortization Schedule? (y/n)");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'y' || answer == 'Y') {
        printf("Amortization Schedule \n");
        printf("--------------------- \n");
        float principal_balance = loan_amount;
        float interest_paid, principal_paid;
        int month = 0;
        printf("Month\tInterest\tPrincipal\tBalance\n");
        while (principal_balance > 0) {
            month++;
            interest_paid = principal_balance * monthly_interest_rate;
            principal_paid = monthly_payment - interest_paid;
            principal_balance -= principal_paid;
            if (principal_balance < 0) {
                principal_paid += principal_balance;
                principal_balance = 0;
            }
            printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", month, interest_paid, principal_paid, principal_balance);
        }
    }
    printf("Thank you for using Mortgage Calculator! \n");
    return 0;
}