//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: intelligent
#include <stdio.h>

int main() {
    float principle, rate, time, emi;

    // Get user input
    printf("Enter principle amount: ");
    scanf("%f", &principle);

    printf("Enter rate of interest: ");
    scanf("%f", &rate);

    printf("Enter time period in years: ");
    scanf("%f", &time);

    // Calculate EMI
    rate = rate / (12 * 100);
    time = time * 12;

    emi = (principle * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

    // Print results
    printf("\nEMI = Rs. %.2f\n", emi);

    printf("\nTotal interest payable (including principle amount) = Rs. %.2f\n", emi * time);

    printf("\nTotal amount payable (including interest) = Rs. %.2f\n", principle + (emi * time));

    return 0;
}