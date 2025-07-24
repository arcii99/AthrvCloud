//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double principle, rate, time, monthly_payment, total_payment, interest;
    int num_month;

    printf("---------------------------\n");
    printf("| RETRO MORTGAGE CALCULATOR |\n");
    printf("---------------------------\n\n");

    printf("Enter the amount of the loan (principle): ");
    scanf("%lf", &principle);

    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &rate);
    rate = rate / 100;

    printf("Enter the duration (in years): ");
    scanf("%lf", &time);
    num_month = time * 12;

    printf("\nCalculating mortgage...\n");

    monthly_payment = (principle * rate * pow(1 + rate, num_month)) / (pow(1 + rate, num_month) - 1);
    interest = monthly_payment * num_month - principle;
    total_payment = monthly_payment * num_month ;

    printf("------------------------------------------------------------\n");
    printf("| Loan Amount: $ %.2lf\t|\tInterest Rate: %.2lf%%\t|\n", principle, rate*100);
    printf("| Duration: %.0lf years\t\t|\tMonthly Payment: $ %.2lf\t|\n", time, monthly_payment);
    printf("| Total Interest: $ %.2lf\t|\tTotal Payment: $ %.2lf\t|\n", interest, total_payment);
    printf("------------------------------------------------------------\n");

    return 0;
}