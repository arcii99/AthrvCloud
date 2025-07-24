//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate the mortgage
float calculateMortgage(float P, float r, float n)
{
    float monthlyInterestRate = r / 1200;
    float mortgage = P * monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -n));
    return mortgage;
}

int main()
{
    float P, r, n, mortgage;
    printf("\nWelcome to the Cyberpunk Mortgage Calculator!\n");
    printf("Enter the principal amount: ");
    scanf("%f", &P);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &r);
    printf("Enter the number of years: ");
    scanf("%f", &n);

    // Calculate the mortgage amount
    mortgage = calculateMortgage(P, r, n);

    // Display the results
    printf("\nYour monthly mortgage payment is: $%f\n", mortgage);
    printf("Congratulations! You are now in debt to the Cyberpunk Mortgage Corporation. Remember to make your payments on time, or you may face the consequences...\n");

    return 0;
}