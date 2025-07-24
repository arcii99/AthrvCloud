//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: immersive
#include <stdio.h>

int main()
{
    float principle, rate, time, emi, interest;
    char choice;

    do {
        printf("Enter loan amount: ");
        scanf("%f", &principle);
        printf("Enter rate of interest: ");
        scanf("%f", &rate);
        printf("Enter term of the loan in years: ");
        scanf("%f", &time);

        rate = rate / (12 * 100); // conversion from annual to monthly and percentage to decimal
        time = time * 12; // conversion from years to months

        emi = (principle * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1); // EMI formula
        interest = emi * time - principle; // total interest paid

        printf("\nEMI: %.2f\n", emi);
        printf("Total interest paid: %.2f\n\n", interest);

        printf("Do you want to calculate EMI for another loan? (y/n): ");
        scanf(" %c", &choice); // space before %c to consume newline character left

    } while (choice == 'y' || choice == 'Y');

    return 0;
}