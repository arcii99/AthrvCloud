//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: accurate
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, time, emi, total_interest, total_payment;
    int n;

    printf("Enter Principal Amount: ");
    scanf("%f", &principal);

    printf("Enter Rate of Interest: ");
    scanf("%f", &rate);

    printf("Enter Term (in years): ");
    scanf("%f", &time);

    printf("Enter number of times interest compounded per year: ");
    scanf("%d", &n);

    rate = rate / (n * 100);    // convert yearly rate into monthly rate
    time = time * 12;    // convert years into months

    // calculate EMI
    emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

    // calculate total payment and interest
    total_payment = emi * time;
    total_interest = total_payment - principal;

    // output results
    printf("\nEMI: %.2f\n", emi);
    printf("Total Payment: %.2f\n", total_payment);
    printf("Total Interest: %.2f\n", total_interest);

    return 0;
}