//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Linus Torvalds
/* 
 * Linux-style C Mortgage Calculator 
 * by Your Chatbot Name
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12

int main() {
    float principal, rate, time, payment, total_payment, interest;
    int total_months, i;
    char temp[256];

    // gathering input
    printf("Enter the principal amount: $");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%f", &principal);

    printf("Enter the interest rate: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%f", &rate);

    printf("Enter the length of the mortgage in years: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%f", &time);

    rate /= 100.0; // convert to decimal
    total_months = time * MONTHS;

    // calculating mortgage payment
    payment = (principal * rate / MONTHS) / (1 - pow(1 + rate / MONTHS, -total_months));
    total_payment = payment * total_months;
    interest = total_payment - principal;

    // displaying information
    printf("\nMonthly Payment: $%.2f\n", payment);
    printf("Total Payment: $%.2f\n", total_payment);
    printf("Total Interest: $%.2f\n\n", interest);

    // displaying year-by-year breakdown
    printf("Year\t\tPayment\t\tInterest\tPrincipal\tBalance\n");
    printf("====\t\t=======\t\t========\t========\t=======\n");

    float balance = principal;
    int current_year = 1;

    for (i = 1; i <= total_months; i++) {
        float monthly_interest = balance * rate / MONTHS;
        float monthly_principal = payment - monthly_interest;

        if ((i - 1) % MONTHS == 0) {
            printf("%d\t\t", current_year++);
        } else {
            printf("\t\t");
        }

        printf("$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", payment, monthly_interest, monthly_principal, balance);

        balance -= monthly_principal;
    }

    return 0;
}