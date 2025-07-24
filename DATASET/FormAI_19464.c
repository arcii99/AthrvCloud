//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Introduction
    printf("Greetings, my dear Watson. Today, we shall calculate the monthly mortgage payment for Mr. Holmes.\n");
    // Variables
    float p, i, n, mp;
    // Principal amount
    printf("Firstly, what is the principal amount, Watson?\n");
    scanf("%f", &p);
    // Interest rate
    printf("And what is the annual interest rate, my dear Watson?\n");
    scanf("%f", &i);
    i = i / 1200;
    // Loan term
    printf("Finally, what is the loan term in years, Watson?\n");
    scanf("%f", &n);
    n = n * 12;
    // Calculation
    mp = (p*i)/(1-(pow(1+i,-n)));
    // Result
    printf("Excellent, Watson. The monthly mortgage payment for Mr. Holmes shall be: $%.2f", mp);
    return 0;
}