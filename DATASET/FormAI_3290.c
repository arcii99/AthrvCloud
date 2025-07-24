//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double loan, interest_rate, monthly_rate, payment;
    int years;
    
    printf("Enter the total amount of the loan: ");
    scanf("%lf", &loan);
    
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    
    printf("Enter the number of years: ");
    scanf("%d", &years);
    
    monthly_rate = (interest_rate / 100) / 12;
    payment = loan * monthly_rate / (1 - pow(1 + monthly_rate, -1 * years * 12));
    
    printf("\n");
    printf("Monthly Payment: $%.2lf\n", payment);
    printf("\n");
    
    return 0;
}