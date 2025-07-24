//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>

typedef struct loan {
    double principal;
    double interest_rate;
    double term;
} Loan;

typedef struct payment {
    double monthly_payment;
    double total_interest;
    double total_payment;
} Payment;

void calculate_payment(Loan loan, Payment *p) {
    // Monthly Interest Rate
    double mir = loan.interest_rate / 1200.0;
    
    // Calculate monthly payment
    double numerator = loan.principal * mir * pow(1.0 + mir, loan.term);
    double denominator = pow(1.0 + mir, loan.term) - 1.0;
    p->monthly_payment = numerator / denominator;
    
    // Calculate total interest
    p->total_interest = p->monthly_payment * loan.term - loan.principal;
    
    // Calculate total payment
    p->total_payment = p->monthly_payment * loan.term;
}

int main() {
    Loan l;
    l.principal = 100000.0;
    l.interest_rate = 8.0;
    l.term = 120.0;
    
    Payment p;
    calculate_payment(l, &p);
    
    printf("Principal: $%.2f\n", l.principal);
    printf("Interest rate: %.2f%%\n", l.interest_rate);
    printf("Term: %.0f months\n", l.term);
    printf("Monthly Payment: $%.2f\n", p.monthly_payment);
    printf("Total Interest: $%.2f\n", p.total_interest);
    printf("Total Payment: $%.2f\n", p.total_payment);
    
    return 0;
}