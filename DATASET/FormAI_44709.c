//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float principal, interestRate, monthlyPayment, totalPaid;
    int years;

    printf("Welcome to the Mortgage Calculator!");

    printf("\nEnter Principal (amount borrowed): $");
    scanf("%f", &principal);

    printf("\nEnter Interest Rate (as a decimal): ");
    scanf("%f", &interestRate);

    printf("\nEnter Number of Years: ");
    scanf("%d", &years);

    float monthlyRate = interestRate/12;
    int months = years * 12;
    monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -months));
    totalPaid = monthlyPayment * months;

    printf("\n\nRESULTS:");
    printf("\nMonthly Payment: $%.2f", monthlyPayment);
    printf("\nTotal Paid: $%.2f", totalPaid);

    printf("\n\nWould you like to see an Amortization Schedule? (Y/N): ");
    char input = getchar();

    if(input == 'Y' || input == 'y') {
        printf("\n\nAmortization Schedule:");
        printf("\n========================\n");
        printf("Month\tInterest\tPrincipal\tPayment\t\tBalance\n");
        printf("===============================================================\n");

        float balance = principal;
        for(int i = 1; i <= months; i++) {
            float interest = balance * monthlyRate;
            float paydown = monthlyPayment - interest;
            balance -= paydown;

            printf("%d\t$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", i, interest, paydown, monthlyPayment, balance);

            if(i % 12 == 0) {
                printf("\n");
            }
        }
    }

    printf("\n\nThank you for using the Mortgage Calculator!");
    return 0;
}