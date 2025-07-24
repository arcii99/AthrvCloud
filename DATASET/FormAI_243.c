//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

int main() {
    float mortgage, rate, years;
    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please enter the mortgage amount in dollars: ");
    scanf("%f", &mortgage);
    printf("Please enter the interest rate as a decimal: ");
    scanf("%f", &rate);
    printf("Please enter the number of years for the mortgage: ");
    scanf("%f", &years);
    
    // calculate the monthly payment
    float r = rate / 12;
    float n = years * 12;
    float payment = (mortgage * r * pow(1 + r, n)) / (pow(1 + r, n) - 1);
    
    printf("Your monthly mortgage payment is $%.2f", payment);
    return 0;
}