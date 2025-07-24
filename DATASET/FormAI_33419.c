//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Donald Knuth
#include<stdio.h>
#include<math.h>

int main() {
    float princ, rate, term, mortPayment, interest, balance;
    int numPayments;

    printf("Enter the principal amount: ");
    scanf("%f", &princ);

    printf("Enter the interest rate: ");
    scanf("%f", &rate);

    printf("Enter the term of the loan (in years): ");
    scanf("%f", &term);

    printf("Enter the number of payments: ");
    scanf("%d", &numPayments);

    /* calculate mortgage payment */
    float r = rate / 1200; // monthly interest rate
    mortPayment = (princ * r * pow((1 + r), (numPayments / 12.0))) / (pow((1 + r), (numPayments / 12.0)) - 1);

    /* output mortgage payment */
    printf("Mortgage Payment: $%.2f\n\n", mortPayment);

    /* create amortization table */
    interest = (princ * rate / 1200.0);
    balance = princ;
    printf("%6s %15s %15s %15s\n", "Payment", "Interest", "Principal", "Balance");
    for(int i = 1; i <= numPayments; i++) {
        float principal = mortPayment - interest;
        balance -= principal;

        printf("%6d %15.2f %15.2f %15.2f\n", i, interest, principal, balance);
        
        /* recalculate interest and balance */
        interest = (balance * rate / 1200);
    }

    return 0;
}