//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float amount, rate, monthly_payment;
    int years, months, total_months;
    
    printf("Enter the loan amount: ");
    scanf("%f", &amount);
    
    printf("Enter the interest rate per year: ");
    scanf("%f", &rate);
    
    printf("Enter the number of years: ");
    scanf("%d", &years);
    
    total_months = years * 12;
    
    float monthly_rate = (rate / 100) / 12;
    float power = pow(1 + monthly_rate, total_months);
    
    monthly_payment = (amount * monthly_rate * power) / (power - 1);
    printf("Your monthly payment is: %.2f\n", monthly_payment);
    
    printf("Do you want to see the amortization table? (y/n): ");
    char response;
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y') {
        float balance = amount;
        float monthly_interest, monthly_principal, total_interest = 0;
        printf("\nMonth\tPayment\t\tInterest\tPrincipal\tBalance\n");
        for (int i = 1; i <= total_months; i++) {
            monthly_interest = balance * monthly_rate;
            total_interest += monthly_interest;
            monthly_principal = monthly_payment - monthly_interest;
            balance -= monthly_principal;
            printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", i, monthly_payment, monthly_interest, monthly_principal, balance);
        }
        printf("\nTotal Interest Paid: %.2f", total_interest);
    }
    
    return 0;
}