//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include <stdio.h>
#include <math.h>

int main() {
    float principal, rate, monthlyrate, numpayment, mortgage;
    printf("Welcome to the Happy Mortgage Calculator!\n");
    printf("Please enter the loan amount: ");
    scanf("%f", &principal);
    printf("Please enter the interest rate: ");
    scanf("%f", &rate);
    printf("Please enter the number of years for the loan: ");
    scanf("%f", &numpayment);

    monthlyrate = rate / 1200.0;
    mortgage = (principal * monthlyrate) / (1 - pow((1 + monthlyrate), -(numpayment * 12.0)));

    printf("\n\nYour monthly payment is: $%.2f\n\n", mortgage);
    printf("Congratulations! You are now officially a homeowner!\n\n");
    printf("May you have many happy years in your new home!\n");

    return 0;
}