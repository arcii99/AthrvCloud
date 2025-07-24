//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Romeo and Juliet
// Romeo and Juliet - A Mortgage Calculator

#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, time, monthlyPayment, totalPayment, interest;
    
    printf("Oh, mortgage, mortgage, wherefore art thou, mortgage?\n");
    printf("What is the amount of thine principal? ");
    scanf("%lf", &principal);
    
    printf("\nOh, rate, rate, wherefore art thou, rate?\n");
    printf("What is the yearly interest rate? ");
    scanf("%lf", &rate);
    
    printf("\nOh, time, time, wherefore art thou, time?\n");
    printf("What is the length of the loan in years? ");
    scanf("%lf", &time);
    
    rate = rate / 100;
    monthlyPayment = (principal * rate / 12) / (1 - pow(1 + rate/12, -12 * time));
    totalPayment = monthlyPayment * 12 * time;
    interest = totalPayment - principal;
    
    printf("\nBut soft, what light through yonder window breaks?\n");
    printf("The monthly payment is: $%.2lf\n", monthlyPayment);
    printf("The total payment is: $%.2lf\n", totalPayment);
    printf("The total interest paid is: $%.2lf\n", interest);
    
    return 0;
}