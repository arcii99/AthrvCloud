//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: recursive
#include <stdio.h>

double calculateMortgage(double principal, double interestRate, double term, int payments);

int main() {
    double principal, interestRate, term, monthlyPayment;

    printf("Please enter your loan's principal amount: ");
    scanf("%lf", &principal);

    printf("Please enter your loan's interest rate: ");
    scanf("%lf", &interestRate);
    interestRate /= 100.0;

    printf("Please enter your loan's term (in years): ");
    scanf("%lf", &term);
    term *= 12.0; // convert to months

    printf("Please enter your desired monthly payment: ");
    scanf("%lf", &monthlyPayment);

    int payments = 1;
    double balance = principal;
    double payment = calculateMortgage(principal, interestRate, term, payments);
    double interest, principalPaid;

    printf("\nMonth\tPayment\t\tInterest\tPrincipal\tBalance\n");
    printf("-----------------------------------------------------------------------------\n");

    while (balance > 0.0) {
        interest = balance * interestRate / 12.0;
        if (interest > monthlyPayment) {
            printf("ERROR: Monthly payment is too low to pay off loan.\n");
            return 1;
        }

        if (monthlyPayment > (balance + interest)) {
            monthlyPayment = balance + interest;
        }

        principalPaid = monthlyPayment - interest;
        balance -= principalPaid;

        printf("%d\t$%7.2f\t$%7.2f\t\t$%7.2f\t\t$%7.2f\n", payments, monthlyPayment, interest, principalPaid, balance);

        payments++;
        payment = calculateMortgage(balance, interestRate, term, payments);

        if (payment > balance) {
            printf("ERROR: Monthly payment is too high to pay off loan.\n");
            return 1;
        }
        
        if (payments >= term) {
            printf("ERROR: Loan term exceeded.\n");
            return 1;
        }
    }

    printf("\nLoan paid off in %d months\n", payments-1);
    return 0;
}

double calculateMortgage(double principal, double interestRate, double term, int payments) {
    if (payments > term) {
        return 0.0;
    }

    double monthlyInterestRate = interestRate / 12.0;
    double x = pow(1 + monthlyInterestRate, term);
    double denominator = x - 1;
    double monthlyPayment = (principal * monthlyInterestRate * x) / denominator;

    return monthlyPayment;
}